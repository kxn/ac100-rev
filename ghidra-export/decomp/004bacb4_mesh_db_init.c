// func mesh_db_init @ 004bacb4 size=524

undefined4 mesh_db_init(void)

{
  int iVar1;
  undefined4 uVar2;
  void *__s;
  char *__format;
  
  if (l_mesh_data != 0) {
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    printf("[MESH_ERROR]%s()/%d Mesh data has been inited!\n","mesh_db_init",0x74a);
    return 0xffffffff;
  }
  DAT_00767eb4 = FUN_00407f00("mesh_mutex",1);
  if (DAT_00767eb4 == 0) {
    if (mesh_err_switch == '\0') goto LAB_004bae24;
    __format = "[MESH_ERROR]%s()/%d Create database mutex failed.\n";
    uVar2 = 0x752;
  }
  else {
    iVar1 = mesh_global_config_init();
    if (iVar1 == 0) {
      DAT_00767f58 = 0;
      FUN_0051ad88(&DAT_00767f5c);
      uVar2 = apmngr_db_get_ap_max();
      DAT_00767f68 = FUN_004080a0(_mesh_discover_ap_obj_hash_func,_mesh_discover_ap_key_hash_func,
                                  _mesh_discover_ap_cmp_func,uVar2);
      if (DAT_00767f68 == 0) {
        if (mesh_err_switch == '\0') goto LAB_004bae24;
        __format = "[MESH_ERROR]%s()/%d Create discover hash failed.\n";
        uVar2 = 0x760;
      }
      else {
        iVar1 = apmngr_db_get_ap_max();
        __s = (void *)FUN_00408450(iVar1 << 3,0x764);
        if (__s != (void *)0x0) {
          DAT_00767f6c = __s;
          iVar1 = apmngr_db_get_ap_max();
          memset(__s,0,iVar1 << 3);
          DAT_00767f7c = 0xffff;
          DAT_00767f80 = 1;
          FUN_0051ad88(&DAT_00767f90);
          apmngr_db_foreach_proc(0xe0000,_mesh_ap_entry_init_from_ap_entry,0);
          apmngr_db_foreach_proc(0xff70ffff,_mesh_ap_entry_init_from_ap_entry,0);
          l_mesh_data = 1;
          return 0;
        }
        DAT_00767f6c = (void *)0x0;
        if (mesh_err_switch == '\0') goto LAB_004bae24;
        __format = "[MESH_ERROR]%s()/%d Create ap list failed.\n";
        uVar2 = 0x767;
      }
    }
    else {
      if (mesh_err_switch == '\0') goto LAB_004bae24;
      __format = "[MESH_ERROR]%s()/%d Init global config failed.\n";
      uVar2 = 0x757;
    }
  }
  printf(__format,"mesh_db_init",uVar2);
LAB_004bae24:
  mesh_db_uninit();
  return 0xffffffff;
}

