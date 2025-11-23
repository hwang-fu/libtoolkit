#include "files.h"

/**
 * Possible overloads:
 * @li int mk_fd(filename, 0)              // read-write
 * @li int mk_fd(filename, 1)              // read-only
 * @li int mk_fd(filename, 2)              // write-only, append
 * @li int mk_fd(filename, 3)              // write-only, open and truncate to empty if exists.
 */
int mk_simple_fd(BORROWED const char * filename, int mode)
{
    TODO;
}

OWNED Result * fd_simple_read(int fd, u64 size)
{
    TODO;
}

bool fd_simple_write(int fd, BORROWED const u8 * data, u64 size)
{
    TODO;
}

void fd_simple_close(int fd)
{
    if (fd < 0)
    {
#ifdef DEBUG_MODE
        WARNINGF("Warning @%s(): File descriptor '%d' is suspicious, skipped.", __FUNCTION__, fd);
#endif
        return;
    }

    if (EQ(fd, 0))            // stdin
    {
#ifdef DEBUG_MODE
        WARNINGF("Warning @%s(): Trying to close standard input, skipped.", __FUNCTION__);
#endif
    }
    else if (EQ(fd, 1))       // stdout
    {
#ifdef DEBUG_MODE
        WARNINGF("Warning @%s(): Trying to close standard output, skipped.", __FUNCTION__);
#endif
    }
    else if (EQ(fd, 2))       // stderr
    {
#ifdef DEBUG_MODE
        WARNINGF("Warning @%s(): Trying to close standard error output, skipped.", __FUNCTION__);
#endif
    }
    else                    // fd >= 3
    {
fd_safe_close_again:
        if (close(fd) == -1)
        {
            if (errno == EINTR)
            {
                WARNINGF("Warning @%s(): Closing interrupted by signal, retrying...", __FUNCTION__);
                goto fd_safe_close_again;
            }
            else
            {
                PANIC("Error @%s(): Failed to close file descriptor '%d'", __FUNCTION__, fd);
            }
        }
#ifdef DEBUG_MODE
        INFO("@%s(): Successfully closed file descriptor '%d'", __FUNCTION__, fd);
#endif
    }
}

bool filename_is_regular(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISREG(st.st_mode);
}

bool filename_is_directory(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISDIR(st.st_mode);
}

bool filename_is_symbolic_link(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISLNK(st.st_mode);
}

bool filename_is_character_device(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISCHR(st.st_mode);
}

bool filename_is_block_device(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISBLK(st.st_mode);
}

bool filename_is_fifo(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISFIFO(st.st_mode);
}

bool filename_is_socket(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }

    struct stat st;
    if (lstat(filename, &st) != 0)
    {
        return false;
    }

    return S_ISSOCK(st.st_mode);
}

bool filename_exists(BORROWED const char * filename)
{
    assert_filename(filename);
    return EQ(access(filename, F_OK), 0);
}

bool filename_is_readable(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }
    return EQ(access(filename, R_OK), 0);
}

bool filename_is_writable(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }
    return EQ(access(filename, W_OK), 0);
}

bool filename_is_executable(BORROWED const char * filename)
{
    assert_filename(filename);
    if (!filename_exists(filename))
    {
        PANIC("Error @%s(): File '%s' does not exist.", __FUNCTION__, filename);
    }
    return EQ(access(filename, X_OK), 0);
}
