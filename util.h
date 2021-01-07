#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <vector>

#include <QWidget>
#include <QListWidget>

#include <appointy_time.h>
#include <price.h>

auto split(const std::string &str, char delim = '\n') -> std::vector<std::string>;
auto string_to_time(const std::string &str) -> appointy::Time;
auto string_to_price(const std::string &str) -> appointy::Price;
auto add_widget_to_list_widget(QWidget *widget, QListWidget *list, const QSize &size_hint) -> void;
auto remove_item_from_list_widget(QListWidgetItem *item, QListWidget *list) -> void;
auto show_error_with_ok(const std::string &text, const std::string &informative_text) -> void;

#endif // UTIL_H
