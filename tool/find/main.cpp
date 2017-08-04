
#include <QList>
#include <QMap>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QTime>
#include <QDebug>
#include <qtconcurrentmap.h>
#include <QCoreApplication>


//// using namespace QtConcurrent;

/*
    Utility function that recursivily searches for files.
*/
QStringList findFiles(const QString &startDir, QStringList filters)
{
    QStringList names;
    QDir dir(startDir);

    foreach (QString file, dir.entryList(filters, QDir::Files)) {
            qDebug() << "||| file: " << file;
            names += startDir + '/' + file;
        }


    foreach (QString subdir, dir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot)) {

            names += findFiles(startDir + '/' + subdir, filters);
        }

    return names;
}

typedef QMap<QString, int> WordCount;

/*
    Single threaded word counter function.
*/
WordCount singleThreadedWordCount(QStringList files)
{
    WordCount wordCount;
    foreach (QString file, files) {
        QFile f(file);
        f.open(QIODevice::ReadOnly);
        QTextStream textStream(&f);
        while (textStream.atEnd() == false)
            foreach (const QString &word, textStream.readLine().split(' '))
                wordCount[word] += 1;

    }
    return wordCount;
}


// countWords counts the words in a single file. This function is
// called in parallel by several threads and must be thread
// safe.
WordCount func_countWords(const QString &file)
{
    QFile f(file);
    f.open(QIODevice::ReadOnly);
    QTextStream textStream(&f);
    WordCount wordCount;
    ///// int loop =0;
    while (textStream.atEnd() == false)
        foreach (const QString &word, textStream.readLine().split(' ')) {
                   if (!word.isEmpty()) {
                     ///// loop++;
                     wordCount[word] += 1;
                     ////  qDebug() << "|||" << loop << " word:" << word;
                   }
            }

    return wordCount;
}

// reduce adds the results from map to the final
// result. This functor will only be called by one thread
// at a time.
void func_reduce(WordCount &result, const WordCount &w)
{
    QMapIterator<QString, int> i(w);
    while (i.hasNext()) {
        i.next();
        result[i.key()] += i.value();
    }
}

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    int warmsfiles = 0;
    QTime time;
    time.start();

    qDebug() << "finding files...";
    QStringList files_type = findFiles("/Users/dev/", QStringList() << "*.pdf" << "*.odt");
    qDebug() << files_type.count() << "files";
    warmsfiles = time.elapsed();
    qDebug() << "finding files misec:" << warmsfiles;

    qDebug() << "warmup";
    {
        QTime time;
        time.start();
        WordCount total = singleThreadedWordCount(files_type);
    }

    qDebug() << "warmup done";

    int singleThreadTime = 0;
    {
        QTime time;
        time.start();
        WordCount total = singleThreadedWordCount(files_type);
        singleThreadTime = time.elapsed();
        qDebug() << "single thread misec:" << singleThreadTime;
    }

    int mapReduceTime = 0;
    {
        QTime time;
        time.start();
        WordCount total = QtConcurrent::mappedReduced(files_type, func_countWords , func_reduce);
        mapReduceTime = time.elapsed();
        qDebug() << "MapReduce misec:" << mapReduceTime;
    }
    qDebug() << "MapReduce speedup x misec:" << ((double)singleThreadTime - (double)mapReduceTime) / (double)mapReduceTime + 1;
}




