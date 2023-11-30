#include "readuntil.hpp"
#include <assert.h>

ReadUntilIO::ReadUntilIO(std::ifstream ifs, const std::string &delimiter) : ifs(std::move(ifs)), delimiter(delimiter)
{
}

void ReadUntilIO::closeFile()
{
    if (this->ifs.is_open())
    {
        this->ifs.close();
    }
}

ReadUntilIO::~ReadUntilIO()
{
    this->closeFile();
}

bool ends_with(const std::string &str, const std::string &suffix)
{
    if (str.length() < suffix.length())
    {
        return false;
    }
    return str.compare(str.length() - suffix.length(), suffix.length(), suffix) == 0;
}

ssize_t ReadUntilIO::scan_eol(ssize_t len)
{
    const char *start, *n;
    ssize_t maxlen;

    assert(self->buf != NULL);
    assert(self->pos >= 0);

    if (self->pos >= self->string_size)
        return 0;

    /* Move to the end of the line, up to the end of the string, s. */
    maxlen = self->string_size - self->pos;
    if (len < 0 || len > maxlen)
        len = maxlen;

    if (len)
    {
        start = PyBytes_AS_STRING(self->buf) + self->pos;
        n = memchr(start, '\n', len);
        if (n)
            /* Get the length from the current position to the end of
               the line. */
            len = n - start + 1;
    }
    assert(len >= 0);
    assert(self->pos < PY_SSIZE_T_MAX - len);

    return len;
}

std::string ReadUntilIO::readline()
{
    std::string pattern = "$ND$\n";
    std::string readPattern;
    int cnt = 0;

    std::string s, out;

    // while (std::getline(this->ifs, s, '\n'))
    // {
    //     out += s;
    //     out += '\n';
    //     if (ends_with(out, pattern))
    //     {
    //         break;
    //     }
    // }
    // return out;
    std::getline(this->ifs, s, '\n');
    s += '\n';
    return s;
}
