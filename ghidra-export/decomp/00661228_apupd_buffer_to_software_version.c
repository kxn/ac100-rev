// func apupd_buffer_to_software_version @ 00661228 size=272

undefined4 apupd_buffer_to_software_version(undefined2 *param_1,ushort param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_14 [2];
  
  local_14[0] = 0;
  if (((param_1 == (undefined2 *)0x0) || (param_2 < 0xe)) || (param_3 == (undefined2 *)0x0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_buffer_to_software_version",0x58);
    }
  }
  else {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    memcpy(local_14,param_1 + 3,4);
    uVar2 = 0;
    *(undefined4 *)(param_3 + 4) = local_14[0];
    memcpy(local_14,param_1 + 5,4);
    *(undefined4 *)(param_3 + 6) = local_14[0];
  }
  return uVar2;
}

