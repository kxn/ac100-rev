// func mesh_cb_for_rd_op @ 004bc630 size=388

undefined4 mesh_cb_for_rd_op(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  undefined4 uVar3;
  undefined4 local_308;
  undefined4 local_304;
  undefined4 local_300;
  undefined4 local_2fc;
  undefined4 local_2f8;
  undefined4 local_2f4;
  undefined1 auStack_2f0 [20];
  int local_2dc;
  
  memset(auStack_2f0,0,0x2d8);
  local_308 = 0;
  local_304 = 0;
  local_300 = 0;
  local_2fc = 0;
  local_2f8 = 0;
  local_2f4 = 0;
  uVar1 = rdmngr_db_generate_ap_id(param_1);
  iVar2 = apmngr_db_entry_get_by_id(uVar1 & 0xffff,auStack_2f0);
  if (iVar2 == 0) {
    if (((local_2dc != 1) && (local_2dc != 3)) && (local_2dc != 2)) {
      if (mesh_debug_switch == '\0') {
        return 0;
      }
      printf("[MESH_DEBUG]%s()/%d Not cap, no need to handle\n","mesh_cb_for_rd_op",0x1c2);
      return 0;
    }
    iVar2 = rdmngr_db_get_radio_cnt_by_ap_id(uVar1,&local_304,&local_300);
    if ((iVar2 != -1) &&
       (iVar2 = rdmngr_db_get_freq_band_idx(param_1,&local_2fc,&local_2f8), iVar2 == 0)) {
      local_308 = param_1;
      local_2f4 = param_2;
      mesh_db_ap_entry_child_foreach_proc(uVar1 & 0xffff,0,_mesh_cb_child_rd_op,&local_308);
      return 0;
    }
    if (mesh_warning_switch == '\0') {
      return 0xffffffff;
    }
    __format = 
    "[MESH_WARNING]%s()/%d rdmngr_db_get_radio_cnt_by_ap_id or rdmngr_db_get_freq_band_idx of %d failed\n"
    ;
    uVar3 = 0x1c8;
  }
  else {
    if (mesh_warning_switch == '\0') {
      return 0xffffffff;
    }
    __format = "[MESH_WARNING]%s()/%d apmngr_db_entry_get_by_id of %d failed\n";
    uVar3 = 0x1bd;
  }
  printf(__format,"mesh_cb_for_rd_op",uVar3,param_1);
  return 0xffffffff;
}

