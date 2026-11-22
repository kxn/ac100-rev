// func _wserv_del_ap_hash_cb @ 005e9e34 size=76

void _wserv_del_ap_hash_cb(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(DAT_007cbf08 + *param_2 * 4);
  if (iVar1 != 0) {
    FUN_00407f40(iVar1,param_1);
  }
  FUN_00407df0(param_1);
  return;
}

