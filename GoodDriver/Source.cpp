#include "ntddk.h"

VOID Unload(IN PDRIVER_OBJECT DriverObject)
{
	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_TRACE_LEVEL, "\r\n>>>>>>>>>>>     GoodBye from Good Driver ...\r\n\r\n");
}

extern "C"
NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath)
{
	DriverObject->DriverUnload = Unload;

	DbgPrintEx(DPFLTR_IHVDRIVER_ID, DPFLTR_TRACE_LEVEL, "\r\n>>>>>>>>>>>    Hello from Good Driver ...\r\n\r\n");

	return STATUS_SUCCESS;
}
