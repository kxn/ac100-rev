// func _apdb_fwid_hash_init @ 005fbdf0 size=128

undefined4 _apdb_fwid_hash_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004080a0(_apdb_fwid_obj_hash_func,_apdb_fwid_key_hash_func,_apdb_fwid_hash_cmp_func,
                       0x1f);
  *param_1 = iVar1;
  uVar2 = 0;
  if ((iVar1 == 0) && (uVar2 = 0xffffffff, apdb_err_switch != 0)) {
    printf("[APDB_ERROR]%s()/line %d : create fwid hash failed.\n","_apdb_fwid_hash_init",0x386);
  }
  return uVar2;
}

