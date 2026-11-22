// func cw_priv_mesh_public_control_val_destroy @ 005b67f4 size=144

undefined4 cw_priv_mesh_public_control_val_destroy(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n",
             "cw_priv_mesh_public_control_val_destroy",0x6c);
    }
  }
  else {
    if (*(int *)(param_1 + 4) != 0) {
      FUN_00407df0();
    }
    cw_priv_mesh_public_control_sub_ele_free(param_1);
    uVar2 = 0;
    FUN_00407df0(param_1);
  }
  return uVar2;
}

