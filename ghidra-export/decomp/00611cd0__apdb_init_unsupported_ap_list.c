// func _apdb_init_unsupported_ap_list @ 00611cd0 size=216

undefined4 _apdb_init_unsupported_ap_list(void)

{
  char *__format;
  undefined4 uVar1;
  
  if (unsupport_ap_root != 0) {
    cJSON_Delete();
    unsupport_ap_root = 0;
  }
  unsupport_ap_root = cJSON_CreateArray();
  if (unsupport_ap_root == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
    uVar1 = 0x8c3;
  }
  else {
    unsupport_hash =
         FUN_004080a0(_apdb_unsupport_obj_hash_func,_apdb_unsupport_key_hash_func,
                      _apdb_unsupport_cmp_func,600);
    if (unsupport_hash != 0) {
      return 0;
    }
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : Create unsupport_hash failed.\n";
    uVar1 = 0x8cb;
    unsupport_hash = 0;
  }
  printf(__format,"_apdb_init_unsupported_ap_list",uVar1);
  return 0xffffffff;
}

