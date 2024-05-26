#include <gtk/gtk.h>
#include "functions1.cpp"
#include <stdio.h>



// Функция для обработки нажатия кнопки "QUIT"
void on_quit_button_clicked(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}




void on_about_button_clicked(GtkWidget *widget, gpointer data) {
    // Создание диалогового окна
    GtkWidget *dialog = gtk_dialog_new_with_buttons("About", GTK_WINDOW(data),GTK_DIALOG_MODAL, "_BACK", GTK_RESPONSE_CLOSE, NULL);
	gtk_window_maximize(GTK_WINDOW(dialog));
	//gtk_window_fullscreen(GTK_WINDOW(dialog));
    // Создание текстового поля с многострочным текстом
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    // Многоязычный текст об игре
    const gchar *about_text = "Правила классического Морского боя:\n 1. Игровое поле:\n - Каждый игрок имеет собственное игровое поле, которое представляет собой сетку клеток.\n - Сетка обычно имеет размер 10x10, где вертикальные линии обозначают буквы (от A до J), а горизонтальные - числа (от 1 до 10).\n 2. Корабли:\n - Каждый игрок размещает: \n - 4 однопалубных корабля (1 клетка)\n - 3 двухпалубных корабля (2 клетки)\n - 2 трехпалубных корабля (3 клетки)\n - 1 четырехпалубный корабль (4 клетки)\n - Корабли не могут пересекаться или соприкасаться.\n 3. Ход игры:\n - Каждый ход состоит из выбора клетки на поле противника для выстрела.\n - После каждого выстрела игрок сообщает результат противнику: попал ли он в корабль или промахнулся. \n 4. Результаты выстрелов: \n - Если выстрел попал в корабль противника, игрок сообщает об этом и отмечает попадание на своем поле.\n - Если выстрел промахнулся, игрок также сообщает об этом. \n - Если все клетки корабля поражены, корабль считается потопленным, и игрок отмечает это на своем поле.\n - Цель игрока - потопить все корабли противника, попадая в их клетки. \n 5. Победа: \n - Игрок, который первым потопит все корабли противника, объявляется победителем.\n";

    // Установка текста в текстовое поле
    gtk_text_buffer_set_text(buffer, about_text, -1);

    // Создание скроллбара и добавление текстового поля в диалоговое окно
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scroll), text_view);
    gtk_container_set_border_width(GTK_CONTAINER(scroll), 10);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
    GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_box_pack_start(GTK_BOX(gtk_dialog_get_content_area(GTK_DIALOG(dialog))),
    scroll, TRUE, TRUE, 0);

    // Отображение диалогового окна
    gtk_widget_show_all(dialog);

    // Ожидание закрытия диалогового окна
    gint response = gtk_dialog_run(GTK_DIALOG(dialog));
    if (response == GTK_RESPONSE_CLOSE) {
        gtk_widget_destroy(dialog);
    }
}


int main(int argc, char *argv[])
{
	gtk_init(&argc,&argv);
	
	//главное окно
	GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window),"Морской бой");// название окна
	gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);///позиция окна
	gtk_window_maximize(GTK_WINDOW(window));///размер окна
	gtk_container_set_border_width(GTK_CONTAINER(window),55);
	gtk_window_set_icon_from_file(GTK_WINDOW(window),"icon1.png",NULL);
	
	
	// Создание CSS провайдера для стилизации главного окна
    GtkCssProvider *css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(css_provider, " \
        window { background-color: #C0C0C0; } \
        button { background-color: black; color: black	; padding: 10px 20px;font-size: 20px; } \
    ", -1, NULL);
    // Применение стилей к главному окну
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
    GTK_STYLE_PROVIDER(css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

   
	

 // Создание вертикального контейнера
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), vbox);
	GtkWidget *image = gtk_image_new_from_file("icon2.png");
	gtk_box_pack_start(GTK_BOX(vbox), image, FALSE, FALSE, 0);

  
	GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Классический режим");
    gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), "Расширенный режим");
    gtk_combo_box_set_active(GTK_COMBO_BOX(combo), 0); 
    // Установка активного  элемента

    // Создание кнопок
    GtkWidget *vs_bot_button = gtk_button_new_with_label("Против бота");
    GtkWidget *vs_player_button = gtk_button_new_with_label("Против друга");
    GtkWidget *about_button = gtk_button_new_with_label("Об игре");
    GtkWidget *quit_button = gtk_button_new_with_label("Выйти");
    
   
    // Добавление кнопок в контейнер
    gtk_box_pack_start(GTK_BOX(vbox), vs_bot_button , TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), vs_player_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), combo, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), about_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), quit_button, TRUE, TRUE, 0);
 
 
 
   

	g_signal_connect(about_button, "clicked", G_CALLBACK(on_about_button_clicked),NULL);
	g_signal_connect(quit_button, "clicked", G_CALLBACK(on_quit_button_clicked),NULL);
	
	
		
	

	gtk_widget_show_all(window);
	gtk_main();
	
	return 0;
}
