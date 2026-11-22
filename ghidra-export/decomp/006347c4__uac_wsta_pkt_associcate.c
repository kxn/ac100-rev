// func _uac_wsta_pkt_associcate @ 006347c4 size=1468

undefined4
_uac_wsta_pkt_associcate(undefined1 *param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  size_t __n;
  int iVar5;
  undefined4 local_378;
  undefined4 local_374;
  undefined4 local_370;
  undefined4 local_36c;
  int local_368;
  size_t local_364;
  void *local_360;
  char local_35c [20];
  undefined4 local_348;
  undefined4 local_344;
  undefined4 local_340;
  undefined4 local_33c;
  undefined4 local_338;
  undefined4 local_334;
  undefined4 local_330;
  undefined4 local_32c;
  undefined4 local_328;
  undefined4 local_324;
  undefined1 auStack_2f0 [16];
  undefined2 local_2e0;
  undefined1 auStack_2a2 [542];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  local_348 = 0;
  local_344 = 0;
  local_340 = 0;
  local_33c = 0;
  local_338 = 0;
  local_35c[0] = '\0';
  local_35c[1] = '\0';
  local_35c[2] = '\0';
  local_35c[3] = '\0';
  local_35c[4] = '\0';
  local_35c[5] = '\0';
  local_35c[6] = '\0';
  local_35c[7] = '\0';
  local_35c[8] = '\0';
  local_35c[9] = '\0';
  local_35c[10] = '\0';
  local_35c[0xb] = '\0';
  local_35c[0xc] = '\0';
  local_35c[0xd] = '\0';
  local_35c[0xe] = '\0';
  local_35c[0xf] = '\0';
  local_35c[0x10] = '\0';
  local_35c[0x11] = '\0';
  local_35c[0x12] = '\0';
  local_35c[0x13] = '\0';
  local_378 = 0;
  local_374 = 0;
  if (*(uint *)(param_1 + 0xc) < 0x12d) {
    iVar5 = apmngr_db_entry_get_by_mac(param_3,auStack_2f0);
    if (iVar5 != 0) {
      iVar5 = 0x25;
      if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "<wsta>[warning]%s(): %d  -> apmngr_db_entry_get_by_mac() fail.\r\n";
        uVar4 = 0x1b3;
        goto LAB_006349e0;
      }
      goto LAB_0063483c;
    }
    iVar5 = _uac_wsta_do_check(local_2e0,*param_1,param_1[1],param_1 + 2,0);
    local_378 = 0;
    if (iVar5 != 0) goto LAB_0063483c;
    if (g_wsta_debug == 0) {
      uVar4 = *(undefined4 *)(param_1 + 8);
    }
    else {
      iVar1 = is_target_debug_ap();
      if (iVar1 == 0) {
        uVar4 = *(undefined4 *)(param_1 + 8);
      }
      else {
        printf("<wsta>[debug]%s(): %d  -> normal sta:%02x:%02x:%02x:%02x:%02x:%02x\r\n",
               "_uac_wsta_pkt_associcate",0x1bf,(uint)(byte)param_1[2],(uint)(byte)param_1[3],
               (uint)(byte)param_1[4],(uint)(byte)param_1[5],(uint)(byte)param_1[6],
               (uint)(byte)param_1[7]);
        uVar4 = *(undefined4 *)(param_1 + 8);
      }
    }
    iVar1 = uac_wstation_assoc(local_2e0,*param_1,param_1[1],param_1 + 2,uVar4,0,0,0,&local_378);
    if (iVar1 - 3U < 2) {
      snprintf((char *)&local_348,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)*param_3,
               (uint)param_3[1],(uint)param_3[2],(uint)param_3[3],(uint)param_3[4],(uint)param_3[5])
      ;
      snprintf(local_35c,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",(uint)(byte)param_1[2],
               (uint)(byte)param_1[3],(uint)(byte)param_1[4],(uint)(byte)param_1[5],
               (uint)(byte)param_1[6],(uint)(byte)param_1[7]);
      memset(&local_334,0,0x40);
      FUN_00408190(local_84,local_80,local_7c,local_78,local_74,&local_334,0x40,"---");
      if (iVar1 == 3) {
        uVar4 = rdmngr_db_generate_rd_id(local_2e0,*param_1);
        uVar4 = rdmngr_db_get_rd_freq_band(uVar4);
        pcVar2 = (char *)apdb_get_radio_freq_name_by_freq(uVar4);
        pcVar3 = "---";
        if (pcVar2 != (char *)0x0) {
          pcVar3 = pcVar2;
        }
        loggerk_reg(0x5b,0x3a9c,3,*param_1,1,pcVar3,1,auStack_2a2,1,&local_334,1,&local_348,1,
                    local_35c,0);
      }
      else {
        loggerk_reg(0x5b,0x3a9d,1,auStack_2a2,1,&local_334,1,&local_348,1,local_35c,0);
      }
      iVar5 = 0x11;
      if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "<wsta>[warning]%s(): %d  -> uac_wstation_assoc() fail.\r\n";
        uVar4 = 0x1e3;
LAB_006349e0:
        printf(pcVar3,"_uac_wsta_pkt_associcate",uVar4);
      }
      goto LAB_0063483c;
    }
    if (iVar1 == -1) {
      iVar5 = 0x25;
      if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
        pcVar3 = "<wsta>[warning]%s(): %d  -> uac_wstation_assoc() fail.\r\n";
        uVar4 = 0x1e8;
        goto LAB_006349e0;
      }
      goto LAB_0063483c;
    }
    uVar4 = 0;
  }
  else {
    iVar5 = 0x25;
    if ((g_wsta_warning != 0) && (iVar1 = is_target_debug_ap(), iVar1 != 0)) {
      printf("<wsta>[warning]%s(): %d  -> invalid backfill len[%d].\r\n","_uac_wsta_pkt_associcate",
             0x1ac,*(undefined4 *)(param_1 + 0xc));
    }
LAB_0063483c:
    uVar4 = 0x15;
  }
  _uac_wsta_pkt_set_result_code(param_4,uVar4);
  local_334 = 0;
  local_330 = 0;
  local_32c = 0;
  local_328 = 0;
  local_324 = 0;
  local_370 = 0;
  local_36c = 0;
  local_368 = 0;
  local_364 = 0;
  local_360 = (void *)0x0;
  if ((*(int *)(param_1 + 0xc) == 0) ||
     (local_360 = (void *)FUN_00408450(*(int *)(param_1 + 0xc),300), local_360 != (void *)0x0)) {
    __n = *(size_t *)(param_1 + 0xc);
    local_370 = CONCAT13(*param_1,CONCAT12(param_1[1],local_370._2_2_));
    local_364 = __n;
    memcpy((void *)((int)&local_370 + 2),param_1 + 2,6);
    if (local_360 != (void *)0x0) {
      memcpy(local_360,*(void **)(param_1 + 0x10),__n);
    }
    local_368 = iVar5;
    FUN_0051ad88(&local_32c);
    local_334 = 0x12345678;
    local_330 = CONCAT22(4,local_330._2_2_);
    iVar5 = cw_service_msg_add(param_4,0x25,&local_334,1,4,&local_370);
    if (iVar5 == 0) {
      if (local_360 == (void *)0x0) {
        return 0;
      }
      FUN_00407df0();
      return 0;
    }
    if ((g_wsta_error == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00634914;
    pcVar3 = "<wsta>[error]%s(): %d  -> set wsta assoc rslt vendor payload fail!\r\n";
    uVar4 = 0x14b;
  }
  else {
    if ((g_wsta_error == 0) || (iVar5 = is_target_debug_ap(), iVar5 == 0)) goto LAB_00634914;
    pcVar3 = "<wsta>[error]%s(): %d  -> no memory.\r\n";
    uVar4 = 0x12f;
  }
  printf(pcVar3,"_uac_wsta_pkt_assemble_assoc_response_elem",uVar4);
LAB_00634914:
  if (local_360 != (void *)0x0) {
    FUN_00407df0();
  }
  if ((g_wsta_warning != 0) && (iVar5 = is_target_debug_ap(), iVar5 != 0)) {
    printf("<wsta>[warning]%s(): %d  -> _uac_wsta_pkt_assemble_assoc_response_elem() fail.\r\n",
           "_uac_wsta_pkt_associcate",0x201);
  }
  return 0xffffffff;
}

