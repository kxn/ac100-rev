// func _uac_cfg_chk_save @ 005127c0 size=1060

void _uac_cfg_chk_save(void)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char acStack_228 [512];
  
  iVar3 = access("/tmp/ac_config/usr_save_request",0);
  if (iVar3 != 0) {
    return;
  }
  if (uac_cfg_dbg_switch != 0) {
    printf("[UAC_CFG_DEBUG]%s()/line %d : Received saving config request, start...\n",
           "_uac_cfg_chk_save",0xaf);
  }
  iVar3 = 0;
  uac_time_msecs();
  l_cfg_lock = 1;
  do {
    pthread_mutex_lock((pthread_mutex_t *)&cfg_mutex);
    iVar4 = uac_list_first(&cfg_tsd_list);
    do {
      if (iVar4 == 0) {
        bVar2 = true;
        goto LAB_005128ac;
      }
      iVar5 = uac_list_next(iVar4);
      piVar1 = (int *)(iVar4 + 0x10);
      iVar4 = iVar5;
    } while (*piVar1 == 0);
    bVar2 = false;
LAB_005128ac:
    iVar3 = iVar3 + 1;
    pthread_mutex_unlock((pthread_mutex_t *)&cfg_mutex);
    if (bVar2) {
      if (uac_cfg_dbg_switch != 0) {
        printf("[UAC_CFG_DEBUG]%s()/line %d : All msg send finish, try_times = %d\n",
               "_uac_cfg_chk_save",0xc0,iVar3);
      }
      goto LAB_005129d0;
    }
    if (iVar3 == 200) break;
    usleep(25000);
  } while( true );
  if (uac_cfg_err_switch != 0) {
    printf("[UAC_CFG_ERROR]%s()/line %d : Wait for send msg timeout\n","_uac_cfg_chk_save",199);
  }
LAB_005129d0:
  iVar3 = 0;
  do {
    iVar4 = uac_list_first(&cfg_reg_list);
    do {
      if (iVar4 == 0) {
        bVar2 = true;
        goto LAB_00512a2c;
      }
      iVar5 = uac_list_next(iVar4);
      iVar6 = (**(code **)(iVar4 + 0x90))();
      iVar4 = iVar5;
    } while (iVar6 == 0);
    bVar2 = false;
LAB_00512a2c:
    iVar3 = iVar3 + 1;
    if (bVar2) {
      if (uac_cfg_dbg_switch != 0) {
        printf("[UAC_CFG_DEBUG]%s()/line %d : All write sql finish, try_times = %d\n",
               "_uac_cfg_chk_save",0xee,iVar3);
      }
      goto LAB_00512a64;
    }
    if (iVar3 == 600) {
      if (uac_cfg_err_switch != 0) {
        printf("[UAC_CFG_ERROR]%s()/line %d : Wait for write done timeout\n","_uac_cfg_chk_save",
               0xe7);
      }
LAB_00512a64:
      usleep(500000);
      if (uac_cfg_dbg_switch != 0) {
        printf("[UAC_CFG_DEBUG]%s()/line %d : Copy config file to temp dir\n","_uac_cfg_chk_save",
               0xf6);
      }
      iVar3 = uac_list_first(&cfg_reg_list);
      while (iVar3 != 0) {
        iVar4 = uac_list_next(iVar3);
        sprintf(acStack_228,"cp -a %s %s",iVar3 + 0xc,"/tmp/ac_config/");
        system(acStack_228);
        iVar3 = iVar4;
      }
      sprintf(acStack_228,"touch %s","/tmp/ac_config/uac_save_ok");
      system(acStack_228);
      remove("/tmp/ac_config/usr_save_request");
      uac_time_msecs();
      if (uac_cfg_dbg_switch != 0) {
        printf("[UAC_CFG_DEBUG]%s()/line %d : Uac save config done, time used: %llu ms...\n",
               "_uac_cfg_chk_save",0x10b);
      }
      cfg_modify = 0;
      l_cfg_lock = 0;
      return;
    }
    usleep(25000);
  } while( true );
}

