#include "pch.h"
#include "Class1.h"

using namespace FrontendAssembly;
using namespace Platform;
using namespace Windows::Storage;

struct RFILE
{
	StorageFile^ file;
};

EXTERN_C_START
RFILE *frontend_filestream_open(const char *path, retro_file_access access)
{
	return nullptr;
}

int frontend_filestream_close(RFILE *stream)
{
	stream->file->GetType();
	return 0;
}
EXTERN_C_END

Class1::Class1()
{
	struct retro_vfs_interface iface;
	iface.retro_vfs_file_open = frontend_filestream_open;
	iface.retro_vfs_file_close = frontend_filestream_close;
}
