// func tdcp_luci_test @ 0051262c size=140

void tdcp_luci_test(void)

{
  int iVar1;
  undefined1 auStack_208 [68];
  undefined1 auStack_1c4 [444];
  
  memcpy(auStack_208,
         "{\"cloud_status\":{\"table\":\"report_url\",\"filter\":[ ]},\"method\":\"get\"}",0x44);
  memset(auStack_1c4,0,0x1bc);
  iVar1 = tdcpRequest(auStack_208);
  if (tdcp_debug_switch != 0) {
    printf("[TDCP_DEBUG]%s()/%d the response is %s\n","tdcp_luci_test",0x4ab,iVar1);
  }
  if (iVar1 != 0) {
    FUN_00407df0(iVar1);
  }
  return;
}

