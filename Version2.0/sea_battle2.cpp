#include <gtk/gtk.h>
#include <stdio.h>
#include <glib.h>

GtkWidget *secondary_window;

void on_human_classic_mode_button_clicked(GtkWidget *widget, gpointer data) {
    
    gtk_widget_destroy(GTK_WIDGET(secondary_window));
   
}

void on_human_extended_mode_button_clicked(GtkWidget *widget, gpointer data) {
	gtk_widget_destroy(GTK_WIDGET(secondary_window));
	
}

void on_bot_classic_mode_button_clicked(GtkWidget *widget, gpointer data) {
    
    gtk_widget_destroy(GTK_WIDGET(secondary_window));
   
}

void on_bot_extended_mode_button_clicked(GtkWidget *widget, gpointer data) {
	gtk_widget_destroy(GTK_WIDGET(secondary_window));
	
}

void on_vs_bot_button_clicked(GtkWidget *widget, gpointer data) {
	secondary_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(secondary_window),"Против Бота");
	gtk_window_set_position(GTK_WINDOW(secondary_window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(secondary_window), 300, 200);
	
	gtk_container_set_border_width(GTK_CONTAINER(secondary_window),10);

    GtkWidget *vvbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(secondary_window), vvbox);
	
	GtkWidget *classic_mode_button = gtk_button_new_with_label("Классический режим");
    GtkWidget *extended_mode_button = gtk_button_new_with_label("Расширенный режим");
    
    gtk_box_pack_start(GTK_BOX(vvbox), classic_mode_button , TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vvbox), extended_mode_button, TRUE, TRUE, 0);
	
	g_signal_connect(classic_mode_button, "clicked", G_CALLBACK(on_bot_classic_mode_button_clicked), secondary_window);
	g_signal_connect(extended_mode_button, "clicked", G_CALLBACK(on_bot_extended_mode_button_clicked), secondary_window);
	
	gtk_widget_show_all(secondary_window);
    
}

 void on_vs_player_button_clicked(GtkWidget *widget, gpointer data) {
	secondary_window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(secondary_window),GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(secondary_window), 300, 200);
	
	gtk_container_set_border_width(GTK_CONTAINER(secondary_window),10);
	
    GtkWidget *vvbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(secondary_window), vvbox);
	
	GtkWidget *classic_mode_button = gtk_button_new_with_label("Классический режим");
    GtkWidget *extended_mode_button = gtk_button_new_with_label("Расширенный режим");
    
    gtk_box_pack_start(GTK_BOX(vvbox), classic_mode_button , TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vvbox), extended_mode_button, TRUE, TRUE, 0);
	
	g_signal_connect(classic_mode_button, "clicked", G_CALLBACK(on_human_classic_mode_button_clicked), secondary_window);
	g_signal_connect(extended_mode_button, "clicked", G_CALLBACK(on_human_extended_mode_button_clicked), secondary_window);
	
	gtk_widget_show_all(secondary_window);
}

void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

void on_about_button_clicked(GtkWidget *widget, gpointer data) {
    
    GtkWidget *dialog = gtk_dialog_new_with_buttons("About", GTK_WINDOW(data),GTK_DIALOG_MODAL, "_BACK", GTK_RESPONSE_CLOSE, NULL);
	gtk_window_maximize(GTK_WINDOW(dialog));
	
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
 
    const gchar *about_text = "Правила классического Морского боя:\n 1. Игровое поле:\n - Каждый игрок имеет собственное игровое поле, которое представляет собой сетку клеток.\n - Сетка обычно имеет размер 10x10, где вертикальные линии обозначают буквы (от A до J), а горизонтальные - числа (от 1 до 10).\n 2. Корабли:\n - Каждый игрок размещает: \n - 4 однопалубных корабля (1 клетка)\n - 3 двухпалубных корабля (2 клетки)\n - 2 трехпалубных корабля (3 клетки)\n - 1 четырехпалубный корабль (4 клетки)\n - Корабли не могут пересекаться или соприкасаться.\n 3. Ход игры:\n - Каждый ход состоит из выбора клетки на поле противника для выстрела.\n - После каждого выстрела игрок сообщает результат противнику: попал ли он в корабль или промахнулся. \n 4. Результаты выстрелов: \n - Если выстрел попал в корабль противника, игрок сообщает об этом и отмечает попадание на своем поле.\n - Если выстрел промахнулся, игрок также сообщает об этом. \n - Если все клетки корабля поражены, корабль считается потопленным, и игрок отмечает это на своем поле.\n - Цель игрока - потопить все корабли противника, попадая в их клетки. \n 5. Победа: \n - Игрок, который первым потопит все корабли противника, объявляется победителем.\n";

    gtk_text_buffer_set_text(buffer, about_text, -1);
   
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll), text_view);
    gtk_container_set_border_width(GTK_CONTAINER(scroll), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
    GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(dialog))),
    scroll, TRUE, TRUE, 0);

    gtk_widget_show_all(dialog);

    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_CLOSE) {
        gtk_widget_destroy(dialog);
    }
}

int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);
	
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Морской бой");
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
	gtk_window_maximize(GTK_WINDOW(window));
	gtk_container_set_border_width(GTK_CONTAINER(window),80);
	gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon1.png",NULL);

    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, " \
        window { background-color: #C0C0C0; } \
        button { background-color: black; color: black	; padding: 10px 20px;font-size: 20px; } \
    ", -1, NULL);
   
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
    GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
	GtkWidget *image = gtk_image_new_from_file("icon2.png");
	gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);

    GtkWidget *vs_bot_button = gtk_button_new_with_label("Против бота");
    GtkWidget *vs_player_button = gtk_button_new_with_label("Против друга");
    GtkWidget *about_button = gtk_button_new_with_label("Об игре");
    GtkWidget *quit_button = gtk_button_new_with_label("Выйти");
     
    gtk_box_pack_start(GTK_BOX(vbox), vs_bot_button , TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), vs_player_button, TRUE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(vbox), about_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quit_button, TRUE, TRUE, 0);

	g_signal_connect(vs_bot_button, "clicked", G_CALLBACK(on_vs_bot_button_clicked),NULL);
	g_signal_connect(vs_player_button, "clicked", G_CALLBACK(on_vs_player_button_clicked),NULL);
	
	g_signal_connect(about_button, "clicked", G_CALLBACK(on_about_button_clicked),NULL);
	g_signal_connect(quit_button, "clicked", G_CALLBACK(on_quit_button_clicked),NULL);
	
	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
