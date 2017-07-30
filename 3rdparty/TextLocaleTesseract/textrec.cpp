#include "textrec.h"

Tessy& Tessy::operator=(const Tessy& d) {
    filenametess = d.filenametess;
    name_native = d.name_native;
    type = d.type;
    data = d.data;
    return *this;
}





/*

bool LanguageTess::saveDest(const QString dest) {
    QFileInfo info(dest);
    if (type == 1) {
        QByteArray chunk = streams();
        QDir dir;
        if (!dir.exists(info.absolutePath())) {
            dir.mkpath(info.absolutePath());
        }
        QFile file(info.absoluteFilePath());
        if (file.open(QFile::WriteOnly)) {
            file.write(chunk, chunk.length()); // write to stderr
            file.close();
            return true;
        }
    }

    return false;
}

*/


TextRec::TextRec()
{

}
