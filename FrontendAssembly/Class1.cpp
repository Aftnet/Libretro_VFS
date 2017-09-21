#include "pch.h"
#include "Class1.h"

using namespace FrontendAssembly;
using namespace Platform;
using namespace Windows::Storage;

EXTERN_C_START

struct retro_vfs_file_handle
{
	StorageFile^ file;
};

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
