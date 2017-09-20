#include "pch.h"
#include "Class1.h"

using namespace FrontendAssembly;
using namespace Platform;
using namespace Windows::Storage;

struct retro_vfs_file_handle
{
	StorageFile^ file;
};

EXTERN_C_START

retro_vfs_file_handle *frontend_filestream_open(const char *path, uint64_t flags)
{
	return nullptr;
}

int frontend_filestream_close(retro_vfs_file_handle *stream)
{
	stream->file->GetType();
	return 0;
}

EXTERN_C_END

Class1::Class1()
{
	struct retro_vfs_interface iface;
	iface.file_open = frontend_filestream_open;
	iface.file_close = frontend_filestream_close;
}
