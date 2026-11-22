// func wportal_radius_server_check @ 0041f978 size=272

void wportal_radius_server_check
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined1 auStack_58 [64];
  
  memset(auStack_58,0,0x40);
  FUN_00408190(param_1,param_2,param_3,param_4,param_5,auStack_58,0x40,"---");
  if ((wportal_debug_switch != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
    printf("[WPORTAL_DBG]%s()/%d Check radius server addr: %s\n","wportal_radius_server_check",
           0x35d2,auStack_58);
  }
  wportal_db_rds_srv_hash_traverse(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

