// func apdb_nego_clear @ 00601cc4 size=1396

int apdb_nego_clear(void)

{
  void *__s;
  int iVar1;
  size_t __n;
  size_t sVar2;
  char *__format;
  undefined4 uVar3;
  void *__s_00;
  int iVar4;
  FILE *__s_01;
  char *pcVar5;
  int iVar6;
  undefined4 local_30 [2];
  
  local_30[0] = 0;
  if (nego_ap_root == 0) {
    if (apdb_err_switch == 0) {
      return -1;
    }
    printf("[APDB_ERROR]%s()/line %d : nego_ap_root empty\n","apdb_nego_clear",0x12e7);
    return -1;
  }
  FUN_00407e80("apdb_nego_clear");
  FUN_004082d0(l_apdb_mutex,0xffffffff);
  if (l_apdb_ap_item_cnt_cur < 1) {
    __s = (void *)0x0;
LAB_00601d78:
    iVar6 = l_apdb_ap_item_cnt_cur;
    iVar1 = cJSON_GetObjectItem(nego_ap_root,"ap_item_list");
    if (iVar1 == 0) {
      if (apdb_debug_switch == 0) {
LAB_00601f20:
        iVar1 = -1;
      }
      else {
        pcVar5 = "[APDB_DEBUG]%s()/line %d : Fail to parse JSON.\n";
        uVar3 = 0x1300;
LAB_00601f74:
        printf(pcVar5,"apdb_nego_clear",uVar3);
        iVar1 = -1;
      }
      goto LAB_00601e70;
    }
    iVar1 = cJSON_GetArraySize(iVar1);
    if (iVar1 < 1) {
      iVar1 = 0;
      goto LAB_00601e70;
    }
    cJSON_DeleteItemFromObject(nego_ap_root,"ap_item_list");
    iVar1 = cJSON_CreateArray();
    if (iVar1 == 0) {
      if (apdb_err_switch != 0) {
        pcVar5 = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
        uVar3 = 0x1313;
        goto LAB_00601f74;
      }
      goto LAB_00601f20;
    }
    cJSON_AddItemToObject(nego_ap_root,"ap_item_list",iVar1);
    pcVar5 = (char *)cJSON_Print(nego_ap_root);
    if (pcVar5 != (char *)0x0) {
      __n = strlen(pcVar5);
      if (((int)__n < 0x100001) && (__n != 0)) {
        nego_db_manage = 1;
        __s_01 = fopen("/etc/nouci_config/dbs/apdb_nego.db","w");
        if (__s_01 == (FILE *)0x0) {
          if (apdb_err_switch != 0) {
            printf("[APDB_ERROR]%s()/line %d : Failed to open file[%s]\n","apdb_nego_clear",0x132d,
                   "/etc/nouci_config/dbs/apdb_nego.db");
          }
        }
        else {
          sVar2 = fwrite(pcVar5,1,__n,__s_01);
          if (__n == sVar2) {
            if (apdb_debug_switch != 0) {
              printf("[APDB_DEBUG]%s()/line %d : write file %d bytes success\n","apdb_nego_clear",
                     0x133a,__n);
            }
            _apdb_refresh_update_count(1);
            nego_db_manage = 0;
            goto LAB_00602018;
          }
          if (apdb_err_switch != 0) {
            __format = "[APDB_ERROR]%s()/line %d : read apdb data failed.\n";
            uVar3 = 0x1335;
            goto LAB_0060218c;
          }
        }
        goto LAB_00601ff4;
      }
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : file is too large or zero.\n","apdb_nego_clear",0x1323);
      }
      iVar1 = -1;
      __s_00 = (void *)0x0;
      __s_01 = (FILE *)0x0;
      goto LAB_00601e7c;
    }
    __s_01 = (FILE *)0x0;
LAB_00602018:
    _apdb_free_new_db();
    iVar1 = FUN_006017e4();
    if (iVar1 == -1) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : reload apdb failed.\n","_apdb_reload_json_db",0x10fd);
      }
      if (apdb_err_switch != 0) {
        __format = "[APDB_ERROR]%s()/line %d : reload apdb failed.\n";
        uVar3 = 0x1345;
LAB_0060218c:
        printf(__format,"apdb_nego_clear",uVar3);
      }
LAB_00601ff4:
      iVar1 = -1;
      __s_00 = (void *)0x0;
      goto LAB_00601e7c;
    }
    if (apdb_debug_switch != 0) {
      printf("[APDB_DEBUG]%s()/line %d : reload apdb success\n","_apdb_reload_json_db",0x1101);
    }
    __s_00 = (void *)0x0;
    if (0 < l_apdb_ap_item_cnt_new) {
      __s_00 = (void *)FUN_00408450(l_apdb_ap_item_cnt_new * 0x58,0x134b);
      iVar1 = l_apdb_ap_item_cnt_new;
      if (__s_00 == (void *)0x0) {
        if (apdb_err_switch == 0) {
          iVar1 = -1;
        }
        else {
          printf("[APDB_ERROR]%s()/line %d : malloc apdb_ap_item_new failed.\n","apdb_nego_clear",
                 0x134e);
          iVar1 = -1;
        }
        goto LAB_00601e7c;
      }
      memset(__s_00,0,l_apdb_ap_item_cnt_new * 0x58);
      _apdb_ap_item_copy(__s_00,l_apdb_ap_item_new,iVar1);
    }
    iVar4 = l_apdb_ap_item_cnt_new;
    FUN_00407f30(l_apdb_mutex);
    iVar1 = _apdb_proc_callback_list(__s,iVar6,__s_00,iVar4,local_30);
    if (iVar1 == -1) {
      if (apdb_err_switch != 0) {
        printf("[APDB_ERROR]%s()/line %d : process apdb callback function list failed.\n",
               "apdb_nego_clear",0x135d);
      }
      goto LAB_00601e94;
    }
    FUN_004082d0(l_apdb_mutex,0xffffffff);
    _apdb_load_finish();
  }
  else {
    __s = (void *)FUN_00408450(l_apdb_ap_item_cnt_cur * 0x168,0x12f1);
    iVar6 = l_apdb_ap_item_cnt_cur;
    if (__s != (void *)0x0) {
      memset(__s,0,l_apdb_ap_item_cnt_cur * 0x58);
      _apdb_ap_item_copy(__s,l_apdb_ap_item_cur,iVar6);
      goto LAB_00601d78;
    }
    if (apdb_err_switch != 0) {
      printf("[APDB_ERROR]%s()/line %d : malloc apdb_ap_item  failed\n","apdb_nego_clear",0x12f4);
    }
    iVar6 = 0;
    iVar1 = -1;
LAB_00601e70:
    __s_00 = (void *)0x0;
    __s_01 = (FILE *)0x0;
    pcVar5 = (char *)0x0;
LAB_00601e7c:
    iVar4 = 0;
  }
  nego_db_manage = 0;
  FUN_00407f30(l_apdb_mutex);
LAB_00601e94:
  FUN_004082b0(1,"apdb_nego_clear");
  disableLearning = 0;
  if (pcVar5 != (char *)0x0) {
    free(pcVar5);
  }
  if (__s_01 != (FILE *)0x0) {
    fclose(__s_01);
  }
  if (__s_00 != (void *)0x0) {
    _apdb_ap_item_free(__s_00,iVar4);
  }
  if (__s != (void *)0x0) {
    _apdb_ap_item_free(__s,iVar6);
  }
  return iVar1;
}

