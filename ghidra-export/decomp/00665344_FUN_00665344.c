// func FUN_00665344 @ 00665344 size=180

undefined4 FUN_00665344(int param_1,ushort param_2)

{
  int iVar1;
  char *__format;
  undefined4 uVar2;
  undefined4 local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  if (param_1 == 0) {
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: inputs error.\r\n";
    uVar2 = 0x186;
  }
  else {
    local_c = (uint)param_2 << 0x10;
    local_10 = 0xc0a801fd;
    iVar1 = cw_service_msg_add(param_1,10,&local_10,0);
    if (iVar1 != -1) {
      return 0;
    }
    if (g_acpdt_error == 0) {
      return 0xffffffff;
    }
    __format = "[ACPDT_ERROR] %32s() %05d: add capwap control ipv4 failed.\r\n";
    uVar2 = 399;
  }
  printf(__format,"acpdt_capwap_control_ipv4_add",uVar2);
  return 0xffffffff;
}

