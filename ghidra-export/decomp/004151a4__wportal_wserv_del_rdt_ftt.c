// func _wportal_wserv_del_rdt_ftt @ 004151a4 size=100

undefined4 _wportal_wserv_del_rdt_ftt(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_3 == 0) {
    if ((wportal_err_switch != 0) && (iVar2 = is_target_debug_ap(), iVar2 != 0)) {
      printf("[WPORTAL_ERR]%s()/%d Wportal rdt entry is null.\n","_wportal_wserv_del_rdt_ftt",0x1d7c
            );
    }
    return 0xffffffff;
  }
  uVar1 = FUN_00414ea8();
  return uVar1;
}

