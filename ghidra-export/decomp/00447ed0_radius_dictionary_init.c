// func radius_dictionary_init @ 00447ed0 size=528

undefined4 radius_dictionary_init(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = uac_hash_new(_radius_attr_obj_hash_func,_radius_attr_key_hash_func,
                       _radius_attr_hash_cmp_func);
  if (iVar1 == 0) {
    if (radius_err_switch == 0) {
      return 0xffffffff;
    }
    printf("[RADIUS_ERR]%s()/%d Create hash table error\n","radius_dictionary_init",0x35c);
    return 0xffffffff;
  }
  iVar2 = uac_hash_new(_radius_vendor_obj_hash_func,_radius_vendor_key_hash_func,
                       _radius_vendor_hash_cmp_func);
  if (iVar2 == 0) {
    iVar3 = 0;
    if (radius_err_switch != 0) {
      printf("[RADIUS_ERR]%s()/%d Create hash table error\n","radius_dictionary_init",0x363);
      iVar3 = 0;
    }
  }
  else {
    iVar3 = uac_hash_new(_radius_attr_name_obj_hash_func,_radius_attr_name_key_hash_func,
                         _radius_attr_name_hash_cmp_func);
    if (iVar3 == 0) {
      if (radius_err_switch == 0) goto LAB_00447fec;
      uVar5 = 0x36a;
    }
    else {
      iVar4 = uac_hash_new(_radius_vendor_name_obj_hash_func,_radius_vendor_name_key_hash_func,
                           _radius_vendor_name_hash_cmp_func);
      if (iVar4 != 0) {
        *(int *)(param_1 + 0x1c) = iVar4;
        *(int *)(param_1 + 0x10) = iVar1;
        *(int *)(param_1 + 0x14) = iVar2;
        *(int *)(param_1 + 0x18) = iVar3;
        return 0;
      }
      if (radius_err_switch == 0) goto LAB_00447fec;
      uVar5 = 0x371;
    }
    printf("[RADIUS_ERR]%s()/%d Create hash table error\n","radius_dictionary_init",uVar5);
  }
LAB_00447fec:
  uac_hash_delete(iVar1);
  if (iVar2 != 0) {
    uac_hash_delete(iVar2);
  }
  if (iVar3 != 0) {
    uac_hash_delete(iVar3);
  }
  return 0xffffffff;
}

