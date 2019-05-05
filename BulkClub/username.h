#ifndef USERNAME_H
#define USERNAME_H

#include <QString>

class userName
{
public:
    userName();
    //!< default constructor: name is initialized to "Blue Sandshrew Member"
    userName(QString name);
    //!< constructor: accepts any string as the name
    userName(const userName& other);
     //!< Copy constructor: initializes userName object to the values of the passed userName object
    QString getName();
    //!< getName() returns the name of the userName object

private:
    QString name; // QString name variable to store name of the manager

};

#endif // USERNAME_H
