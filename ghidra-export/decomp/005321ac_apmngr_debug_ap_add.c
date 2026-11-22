// func apmngr_debug_ap_add @ 005321ac size=1

/* WARNING: Removing unreachable block (ram,0x005323b0) */
/* WARNING: Removing unreachable block (ram,0x005323cc) */
/* WARNING: Removing unreachable block (ram,0x005323e4) */
/* WARNING: Removing unreachable block (ram,0x005323f4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void apmngr_debug_ap_add(int param_1,int param_2,char param_3)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  char *__format;
  undefined4 uVar9;
  uint uStack_328;
  int iStack_324;
  undefined1 auStack_320 [2];
  undefined1 auStack_31e [6];
  undefined4 uStack_318;
  undefined4 uStack_314;
  undefined4 uStack_310;
  undefined4 uStack_30c;
  undefined1 auStack_308 [18];
  undefined2 uStack_2f6;
  int iStack_2cc;
  undefined4 uStack_2c8;
  undefined2 uStack_2c4;
  undefined1 auStack_2be [4];
  char acStack_2ba [166];
  char acStack_214 [32];
  char acStack_1f4 [16];
  undefined4 uStack_1e4;
  short sStack_100;
  undefined2 uStack_fe;
  undefined2 uStack_fc;
  undefined1 uStack_9c;
  int iStack_98;
  short sStack_88;
  undefined4 uStack_78;
  int iStack_30;
  
  iStack_30 = (int)param_3;
  memset(auStack_308,0,0x2d8);
  iStack_324 = 0;
  uStack_328 = 0;
  if (param_1 == 0) {
    iStack_324 = FUN_00408450(4000,0xdd3);
    _g_apmngr_debug_model_count = 0;
    if (iStack_324 == 0) {
      _g_apmngr_debug_model_count = 0;
      return;
    }
    apdb_traversal(_apmngr_debug_get_all_model_ids,iStack_324);
    uStack_328 = _g_apmngr_debug_model_count;
  }
  else {
    iVar3 = apdb_get_aps_by_name(param_1,&iStack_324,&uStack_328);
    if (iVar3 != 0) {
      __format = "Failed to find AP-Type : %s.";
      goto code_r0x005324a8;
    }
  }
  uStack_318 = 0xffffffff;
  uStack_314 = 0xffffffff;
  uStack_310 = 0xffffffff;
  uStack_30c = 0xffffffff;
  param_1 = 0;
  apmngr_db_entry_init(auStack_308,&uStack_318,0,0);
  for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {
    strncpy(acStack_2ba,"SimAP",0x99);
    iVar5 = iStack_324;
    uVar4 = random();
    if (uStack_328 == 0) {
      trap(7);
    }
    uVar9 = *(undefined4 *)(iVar5 + (uVar4 % uStack_328) * 4);
    iStack_2cc = iStack_30;
    uStack_2f6 = 0;
    uStack_2c4 = 1;
    uStack_2c8 = uVar9;
    uVar4 = (uint)auStack_2be & 3;
    puVar2 = (uint *)(auStack_2be + -uVar4);
    *puVar2 = *puVar2 & -1 << (4 - uVar4) * 8 | _g_apmngr_debug_ap_start >> uVar4 * 8;
    puVar1 = auStack_2be + 3;
    uVar4 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar4) =
         *(uint *)(puVar1 + -uVar4) & 0xffffffffU >> (uVar4 + 1) * 8 |
         _g_apmngr_debug_ap_start << (3 - uVar4) * 8;
    strncpy(acStack_214,"admin",0x1f);
    strncpy(acStack_1f4,"tplink",0xf);
    iVar5 = apdb_support_ap_trunk_by_id(uVar9,&uStack_318);
    if (iVar5 == 0) {
      uStack_1e4 = 0xffffffff;
    }
    else {
      uStack_1e4 = 0;
    }
    iVar5 = apdb_is_hdap_by_id(uStack_2c8,&uStack_318);
    if (iVar5 == 0) {
      iVar7 = apmngr_ap_add(auStack_308,&uStack_318,0,0,1);
    }
    else {
      uVar6 = (int)auStack_2be + 2;
      uVar4 = (uint)auStack_31e & 3;
      puVar2 = (uint *)(auStack_31e + -uVar4);
      *puVar2 = *puVar2 & -1 << (4 - uVar4) * 8 | uVar6 >> uVar4 * 8;
      puVar1 = auStack_31e + 3;
      uVar4 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar4) =
           *(uint *)(puVar1 + -uVar4) & 0xffffffffU >> (uVar4 + 1) * 8 | uVar6 << (3 - uVar4) * 8;
      iVar7 = apmngr_hdap_add(auStack_308,&uStack_318,auStack_320,0,1);
    }
    if (iVar7 == 0xffff) {
      iVar7 = param_1 + 1;
      param_1 = param_1 + 2;
      if (iVar5 == 0) {
        param_1 = iVar7;
      }
    }
    else {
      uStack_78 = 0xffffffff;
      iStack_98 = _g_apmngr_debug_ap_start + 0xc0a80001;
      uStack_9c = 1;
      lVar8 = random();
      sStack_88 = (short)(lVar8 % 0xfbff) + 0x400;
      sStack_100 = (short)((int)_g_apmngr_debug_ap_start / 10000) + 1;
      uStack_fc = (undefined2)((int)_g_apmngr_debug_ap_start % 100);
      uStack_fe = (undefined2)(((int)_g_apmngr_debug_ap_start / 100) % 100);
      apmngr_db_entry_run_set(iVar7,&sStack_100);
      apmngr_db_ap_run_state_update(iVar7,2);
      apmngr_checksum_update(auStack_308,0);
      apmngr_db_ap_led_update(iVar7,1);
      apmngr_db_ap_run_state_update(iVar7,2);
      multi_link_status_switch(iVar7,1,1,0,0,0);
    }
    uVar4 = _g_apmngr_debug_ap_start + 1;
    if (iVar5 != 0) {
      iVar3 = iVar3 + 1;
      uVar4 = _g_apmngr_debug_ap_start + 3;
    }
    _g_apmngr_debug_ap_start = uVar4;
  }
  FUN_00407df0(iStack_324);
  param_1 = param_2 - param_1;
  if (param_1 < 1) {
    return;
  }
  __format = "Success to add %d sim-AP(s).\n";
code_r0x005324a8:
  printf(__format,param_1);
  return;
}

