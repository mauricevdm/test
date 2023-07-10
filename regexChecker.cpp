#include "regexchecker.h"
#include <QRegularExpression>

RegExChecker::RegExChecker(QList<QStringList> list): listToCheck(list)
{
}

QStringList RegExChecker::check()
{
    QRegularExpression numberInWord(QRegularExpression::anchoredPattern("[a-z]*\\d+[a-z]*"));
    QRegularExpression capsInWord(QRegularExpression::anchoredPattern("[a-zA-Z]{1,1}[a-z]*[A-Z]+[a-z]*"));
    QRegularExpression symbolInWord(QRegularExpression::anchoredPattern("[a-z]*(\\W[^\\n]|@)+[a-z]*"));
    QRegularExpression otherInWord(QRegularExpression::anchoredPattern("[a-z]*[@*<#]+[a-z]*"));

    QString errorLine;
    QStringList listOfErrors;

    for (int line=0; line<listToCheck.size(); line++)
    {
        for (int word=0; word<listToCheck.at(line).size(); word++)
        {
            QString currentWord = listToCheck.at(line).at(word);
            if (numberInWord.match(currentWord).hasMatch() || capsInWord.match(currentWord).hasMatch()
                    || symbolInWord.match(currentWord).hasMatch() || otherInWord.match(currentWord).hasMatch())
            {
                errorLine.clear();
                errorLine += "Line " + QString::number(line+1) + ", word " + QString::number(word+1) + ": " + currentWord;
                listOfErrors.append(errorLine);
            }
        }
    }

    return listOfErrors;
}
