#include <util.h>

#include <sstream>

#include <QMessageBox>

#include <appointy_exception.h>

auto split(const std::string &str, char delim) -> std::vector<std::string>
{
    std::stringstream ss {str};
    std::string token;
    std::vector<std::string> substrs;
    while(std::getline(ss, token, delim))
    {
        substrs.push_back(token);
    }

    return substrs;
}

auto string_to_time(const std::string &str) -> appointy::Time
{
    auto parts = split(str, ':');
    if(parts.size() != 3)
    {
        throw appointy::Exception {"The string provided is of wrong format"};
    }

    return appointy::Time
    {
        std::stoi(parts[0]),
        std::stoi(parts[1]),
        std::stoi(parts[2])
    };
}

auto string_to_price(const std::string &str) -> appointy::Price
{
    auto parts = split(str, '.');
    if(parts.size() != 2)
    {
        parts = split(str, ',');
        if(parts.size() != 2)
        {
            throw appointy::Exception {"The string provided is of wrong format"};
        }
    }

    if(parts[1].length() > 2)
    {
        throw appointy::Exception {"The string provided is of wrong format: too many characters after the decimal point"};
    }

    return appointy::Price
    {
        std::stoi(parts[0]),
        parts[1].length() != 1? std::stoi(parts[1]) : std::stoi(parts[1]) * 10
    };
}

auto add_widget_to_list_widget(QWidget *widget, QListWidget *list, const QSize &size_hint) -> void
{
    auto *item = new QListWidgetItem {list};
    list->addItem(item);
    list->setItemWidget(item, widget);
    item->setSizeHint(size_hint);
}

auto remove_item_from_list_widget(QListWidgetItem *item, QListWidget *list) -> void
{
    list->itemWidget(item)->hide();
    list->removeItemWidget(item);
}

auto show_error_with_ok(const std::string &text, const std::string &informative_text) -> void
{
    QMessageBox msg_box {QMessageBox::Critical, "Error", text.c_str(), QMessageBox::Ok, nullptr};
    msg_box.setInformativeText(informative_text.c_str());
    msg_box.setDefaultButton(QMessageBox::Ok);
    msg_box.exec();
}
