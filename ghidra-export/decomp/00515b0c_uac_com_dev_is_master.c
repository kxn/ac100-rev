// func uac_com_dev_is_master @ 00515b0c size=1356

undefined4 uac_com_dev_is_master(void)

{
  int iVar1;
  FILE *__stream;
  size_t __n;
  void *__ptr;
  void *pvVar2;
  int iVar3;
  int iVar4;
  char *__format;
  undefined4 uVar5;
  int iVar6;
  code *pcVar7;
  char acStack_40 [40];
  
  memset(acStack_40,0,0x21);
  iVar1 = uac_com_get_dev_type(acStack_40,0x21);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = strncmp(acStack_40,"SMBWIRELESSROUTER",0x21);
  if (iVar1 != 0) {
    if (uac_comm_dbg_switch == 0) {
      return 1;
    }
    printf("[UAC_COMM_DBG]%s()/line %d : not XVR device, it\'s master device\n",
           "uac_com_dev_is_master",0x50c);
    return 1;
  }
  __stream = fopen("/tmp/etc/config/mapd.json","r+");
  if (__stream == (FILE *)0x0) {
    if (uac_comm_dbg_switch == 0) {
      return 0;
    }
    printf("[UAC_COMM_DBG]%s()/line %d : Failed to open file[%s]\n","uac_com_dev_is_master",0x512,
           "/tmp/etc/config/mapd.json");
    return 0;
  }
  fseek(__stream,0,2);
  __n = ftell(__stream);
  fseek(__stream,0,0);
  __ptr = (void *)uac_mem_malloc_my(__n + 1,0x518);
  if (__ptr == (void *)0x0) {
    if (uac_comm_err_switch != 0) {
      printf("[UAC_COMM_ERR]%s()/line %d : file data malloc error\n\n","uac_com_dev_is_master",0x51b
            );
    }
    fclose(__stream);
    return 0;
  }
  fread(__ptr,1,__n,__stream);
  fclose(__stream);
  pvVar2 = (void *)cJSON_Parse(__ptr);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = __ptr;
    if (uac_comm_err_switch == 0) {
      pcVar7 = uac_mem_free_my;
    }
    else {
      printf("[UAC_COMM_ERR]%s()/line %d : get root obj failed.\n","uac_com_dev_is_master",0x525);
      pcVar7 = uac_mem_free_my;
    }
    goto LAB_00515d20;
  }
  uac_mem_free_my(__ptr);
  iVar1 = cJSON_GetObjectItem(pvVar2,"business");
  if (iVar1 == 0) {
    if (uac_comm_err_switch != 0) {
      uVar5 = 0x52e;
      __format = "[UAC_COMM_ERR]%s()/line %d : business data json error\n";
      goto LAB_00515dc4;
    }
  }
  else {
    iVar3 = cJSON_GetObjectItem(iVar1,"role_selection");
    if (iVar3 == 0) {
      if (uac_comm_err_switch != 0) {
        uVar5 = 0x534;
        __format = "[UAC_COMM_ERR]%s()/line %d : role selection data json error\n";
        goto LAB_00515dc4;
      }
    }
    else {
      iVar4 = cJSON_GetObjectItem(iVar3,&DAT_00698198);
      if ((iVar4 == 0) || (*(int *)(iVar4 + 0xc) != 3)) {
        if (uac_comm_err_switch != 0) {
          uVar5 = 0x53a;
          __format = "[UAC_COMM_ERR]%s()/line %d : role data json error\n";
          goto LAB_00515dc4;
        }
      }
      else {
        iVar6 = *(int *)(iVar4 + 0x14);
        if (uac_comm_dbg_switch != 0) {
          printf("[UAC_COMM_DBG]%s()/line %d : role :%d\n","uac_com_dev_is_master",0x53e,iVar6);
        }
        if (iVar6 == 0) {
          iVar1 = cJSON_GetObjectItem(iVar3,"paired");
          if ((iVar1 == 0) || (*(int *)(iVar4 + 0xc) != 3)) {
            if (uac_comm_err_switch != 0) {
              uVar5 = 0x544;
              __format = "[UAC_COMM_ERR]%s()/line %d : pair data json error\n";
              goto LAB_00515dc4;
            }
          }
          else {
            iVar1 = *(int *)(iVar1 + 0x14);
            if (uac_comm_dbg_switch != 0) {
              printf("[UAC_COMM_DBG]%s()/line %d : pair :%d\n","uac_com_dev_is_master",0x548,iVar1);
            }
            if (iVar1 != 0) {
LAB_00516010:
              cJSON_Delete(pvVar2);
              return 1;
            }
            if (uac_comm_dbg_switch != 0) {
              uVar5 = 0x54b;
              __format = "[UAC_COMM_DBG]%s()/line %d : XVR unpair re device, not master device\n";
              goto LAB_00515dc4;
            }
          }
        }
        else {
          iVar1 = cJSON_GetObjectItem(iVar1,"role_info");
          if (iVar1 == 0) {
            if (uac_comm_err_switch == 0) goto LAB_00515d1c;
            uVar5 = 0x554;
            __format = "[UAC_COMM_ERR]%s()/line %d : role info data json error\n";
          }
          else {
            iVar1 = cJSON_GetObjectItem(iVar1,"is_agent");
            if ((iVar1 == 0) || (*(int *)(iVar1 + 0xc) != 3)) {
              if (uac_comm_err_switch == 0) goto LAB_00515d1c;
              uVar5 = 0x55a;
              __format = "[UAC_COMM_ERR]%s()/line %d : role info data json error\n";
            }
            else {
              pcVar7 = cJSON_Delete;
              if (*(int *)(iVar1 + 0x14) != 1) goto LAB_00516010;
              if (uac_comm_dbg_switch == 0) goto LAB_00515d20;
              uVar5 = 0x560;
              __format = "[UAC_COMM_DBG]%s()/line %d : CAP XVR, not master device\n";
            }
          }
LAB_00515dc4:
          printf(__format,"uac_com_dev_is_master",uVar5);
        }
      }
    }
  }
LAB_00515d1c:
  pcVar7 = cJSON_Delete;
LAB_00515d20:
  (*pcVar7)(pvVar2);
  return 0;
}

