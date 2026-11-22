// func cw_ac_data_destroy @ 00589eac size=152

undefined4 cw_ac_data_destroy(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    printf("[ASSERT]%32s():%4d assert(%s) failed\n","cw_ac_data_destroy",0x314,&DAT_006de7a4);
    uVar1 = 0xffffffff;
  }
  else {
    if ((capwap_debug_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[CW_DEBUG]%32s():%4d ac_data[%p] free.\n","cw_ac_data_destroy",0x316,param_1);
    }
    snapshot_list_destroy(param_1 + 0x94);
    uVar1 = 0;
  }
  return uVar1;
}

