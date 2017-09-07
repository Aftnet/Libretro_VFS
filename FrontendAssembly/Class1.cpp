#include "pch.h"
#include "Class1.h"

using namespace FrontendAssembly;
using namespace Platform;
using namespace Windows::Storage;

struct _libretro_iobuf
{
	StorageFile^ file;
};

EXTERN_C_START
RFILE *frontend_filestream_open(const char *path, unsigned mode)
{
	return nullptr;
}

int frontend_filestream_close(RFILE *stream)
{
	auto path = stream->file->Path;
	return 0;
}
EXTERN_C_END

Class1::Class1()
{
	retro_set_file_open(frontend_filestream_open);
	retro_set_file_close(frontend_filestream_close);
}
