// func cw_priv_mesh_private_control_val_destroy @ 0057b038 size=124

undefined4 cw_priv_mesh_private_control_val_destroy(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
    if ((capwap_err_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("[CW_ERROR]%32s():%4d input parameter is wrong\n",
             "cw_priv_mesh_private_control_val_destroy",0x8b);
    }
  }
  else {
    cw_priv_mesh_private_control_sub_ele_free();
    uVar2 = 0;
    FUN_00407df0(param_1);
  }
  return uVar2;
}

