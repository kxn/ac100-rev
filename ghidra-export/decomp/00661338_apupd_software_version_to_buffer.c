// func apupd_software_version_to_buffer @ 00661338 size=260

undefined4 apupd_software_version_to_buffer(undefined2 *param_1,undefined1 *param_2,ushort param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 uStack_17;
  undefined4 local_14 [2];
  
  local_14[0] = 0;
  if (((param_1 == (undefined2 *)0x0) || (param_2 == (undefined1 *)0x0)) || (param_3 < 0xe)) {
    uVar3 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_software_version_to_buffer",0x7f);
    }
  }
  else {
    uVar1 = *param_1;
    param_2[1] = (char)uVar1;
    *param_2 = (char)((ushort)uVar1 >> 8);
    uVar1 = param_1[1];
    param_2[2] = (char)((ushort)uVar1 >> 8);
    uStack_17 = (undefined1)uVar1;
    param_2[3] = uStack_17;
    uVar1 = param_1[2];
    param_2[4] = (char)((ushort)uVar1 >> 8);
    uStack_17 = (undefined1)uVar1;
    param_2[5] = uStack_17;
    local_14[0] = *(undefined4 *)(param_1 + 4);
    memcpy(param_2 + 6,local_14,4);
    local_14[0] = *(undefined4 *)(param_1 + 6);
    uVar3 = 0;
    memcpy(param_2 + 10,local_14,4);
  }
  return uVar3;
}

