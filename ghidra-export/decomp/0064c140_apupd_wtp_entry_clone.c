// func apupd_wtp_entry_clone @ 0064c140 size=252

undefined4 apupd_wtp_entry_clone(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0xffffffff;
    if ((g_apupd_error != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[APUPD_ERROR]%32s() %05d: inputs error.\r\n","apupd_wtp_entry_clone",0xc2f);
    }
  }
  else {
    memcpy((void *)(param_1 + 0x18),(void *)(param_2 + 0x18),0x14);
    *(undefined2 *)(param_1 + 0x2c) = *(undefined2 *)(param_2 + 0x2c);
    memcpy((void *)(param_1 + 0x2e),(void *)(param_2 + 0x2e),6);
    *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
    memcpy((void *)(param_1 + 0x38),(void *)(param_2 + 0x38),0x10);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(param_2 + 0x48);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    memcpy((void *)(param_1 + 0x58),(void *)(param_2 + 0x58),0x10);
    *(undefined1 *)(param_1 + 0x68) = *(undefined1 *)(param_2 + 0x68);
    uVar2 = 0;
    memcpy((void *)(param_1 + 0x69),(void *)(param_2 + 0x69),(uint)*(byte *)(param_2 + 0x68) << 4);
  }
  return uVar2;
}

