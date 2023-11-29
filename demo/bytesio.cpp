#include "Python.h"

static Py_ssize_t scan_eol(bytesio *self, Py_ssize_t len)
{
    const char *start, *n;
    Py_ssize_t maxlen;

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