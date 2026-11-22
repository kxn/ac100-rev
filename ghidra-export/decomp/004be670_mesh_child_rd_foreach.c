// func mesh_child_rd_foreach @ 004be670 size=1

undefined4 mesh_child_rd_foreach(undefined4 param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined4 uStack_308;
  undefined4 uStack_304;
  undefined4 uStack_300;
  int iStack_2fc;
  undefined4 uStack_2f8;
  undefined1 auStack_2f0 [20];
  int iStack_2dc;
  
  memset(auStack_2f0,0,0x2d8);
  uStack_310 = 0;
  uStack_30c = 0;
  uStack_308 = 0;
  uStack_304 = 0;
  uStack_300 = 0;
  iStack_2fc = 0;
  uStack_2f8 = 0;
  uVar1 = rdmngr_db_generate_ap_id(param_1);
  if (param_2 == 0) {
    uVar5 = 0xffffffff;
    if (mesh_err_switch == '\0') {
      return 0xffffffff;
    }
    pcVar3 = "[MESH_ERROR]%s()/%d pf is NULL\n";
    uVar4 = 0x1df;
code_r0x004be784:
    printf(pcVar3,"mesh_child_rd_foreach",uVar4);
  }
  else {
    iVar2 = apmngr_db_entry_get_by_id(uVar1 & 0xffff,auStack_2f0);
    if (iVar2 == 0) {
      if (((iStack_2dc != 1) && (iStack_2dc != 3)) && (iStack_2dc != 2)) {
        uVar5 = 0;
        if (mesh_debug_switch == '\0') {
          return 0;
        }
        pcVar3 = "[MESH_DEBUG]%s()/%d Not cap, no need to handle\n";
        uVar4 = 0x1e9;
        goto code_r0x004be784;
      }
      iVar2 = rdmngr_db_get_radio_cnt_by_ap_id(uVar1,&uStack_30c,&uStack_308);
      if ((iVar2 != -1) &&
         (iVar2 = rdmngr_db_get_freq_band_idx(param_1,&uStack_304,&uStack_300), iVar2 == 0)) {
        uStack_310 = param_1;
        iStack_2fc = param_2;
        uStack_2f8 = param_3;
        mesh_db_ap_entry_child_foreach_proc(uVar1 & 0xffff,0,_mesh_cb_child_rd_foreach,&uStack_310);
        return 0;
      }
      if (mesh_warning_switch == '\0') {
        return 0xffffffff;
      }
      pcVar3 = 
      "[MESH_WARNING]%s()/%d rdmngr_db_get_radio_cnt_by_ap_id or rdmngr_db_get_freq_band_idx of %d failed\n"
      ;
      uVar4 = 0x1ef;
    }
    else {
      if (mesh_warning_switch == '\0') {
        return 0xffffffff;
      }
      pcVar3 = "[MESH_WARNING]%s()/%d apmngr_db_entry_get_by_id of %d failed\n";
      uVar4 = 0x1e4;
    }
    uVar5 = 0xffffffff;
    printf(pcVar3,"mesh_child_rd_foreach",uVar4,param_1);
  }
  return uVar5;
}

