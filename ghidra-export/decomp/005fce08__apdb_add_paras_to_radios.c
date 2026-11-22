// func _apdb_add_paras_to_radios @ 005fce08 size=2316

undefined4 _apdb_add_paras_to_radios(undefined4 param_1,int param_2)

{
  short sVar1;
  int iVar2;
  char cVar3;
  char *__format;
  undefined *puVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [40];
  
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  memset(auStack_38,0,0x21);
  uVar6 = __floatsidf((int)*(short *)(param_2 + 0x1c));
  iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
  if (iVar2 == 0) {
    if (apdb_err_switch == 0) {
      return 0xffffffff;
    }
    __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
    uVar5 = 0x14ae;
  }
  else {
    cJSON_AddItemToObject(param_1,"max_ssid",iVar2);
    uVar6 = __floatsidf((int)*(short *)(param_2 + 0x1e));
    iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
    if (iVar2 == 0) {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
      uVar5 = 0x14b9;
    }
    else {
      cJSON_AddItemToObject(param_1,"max_stations",iVar2);
      if (*(short *)(param_2 + 0x20) == 0) {
        sVar1 = *(short *)(param_2 + 0x22);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x14c7;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"max_tx_power",iVar2);
        sVar1 = *(short *)(param_2 + 0x22);
      }
      if (sVar1 == 0) {
        sVar1 = *(short *)(param_2 + 0x24);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x14d5;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"min_tx_power",iVar2);
        sVar1 = *(short *)(param_2 + 0x24);
      }
      if (sVar1 == 0) {
        sVar1 = *(short *)(param_2 + 0x26);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x14e1;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"dft_tx_power",iVar2);
        sVar1 = *(short *)(param_2 + 0x26);
      }
      if (sVar1 == 0) {
        sVar1 = *(short *)(param_2 + 0x28);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x14ee;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"real_max_tx_power",iVar2);
        sVar1 = *(short *)(param_2 + 0x28);
      }
      if (sVar1 == 0) {
        sVar1 = *(short *)(param_2 + 0x2a);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x14fc;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"real_min_tx_power",iVar2);
        sVar1 = *(short *)(param_2 + 0x2a);
      }
      if (sVar1 == 0) {
        iVar2 = *(int *)(param_2 + 0x30);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x150a;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"real_dft_tx_power",iVar2);
        iVar2 = *(int *)(param_2 + 0x30);
      }
      if (iVar2 == -1) {
        cVar3 = *(char *)(param_2 + 0x2c);
      }
      else {
        uVar6 = __floatsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1517;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"dft_bw_mode",iVar2);
        cVar3 = *(char *)(param_2 + 0x2c);
      }
      if (cVar3 == '\0') {
        cVar3 = *(char *)(param_2 + 0x2d);
      }
      else {
        uVar6 = __floatunsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1524;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"max_tx_stream",iVar2);
        cVar3 = *(char *)(param_2 + 0x2d);
      }
      if (cVar3 == '\0') {
        cVar3 = *(char *)(param_2 + 0x38);
      }
      else {
        uVar6 = __floatunsidf();
        iVar2 = cJSON_CreateNumber((int)((ulonglong)uVar6 >> 0x20),(int)uVar6);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1531;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"max_rx_stream",iVar2);
        cVar3 = *(char *)(param_2 + 0x38);
      }
      if (cVar3 != '\0') {
        iVar2 = cJSON_CreateString(param_2 + 0x38);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x153e;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"mutex_channel",iVar2);
      }
      iVar2 = memcmp((void *)(param_2 + 0x100),&local_48,0x10);
      if (iVar2 == 0) {
        iVar2 = *(int *)(param_2 + 4);
      }
      else {
        _apdb_extend_cap_transfer_to_str((void *)(param_2 + 0x100),0x10,auStack_38,0x21);
        iVar2 = cJSON_CreateString(auStack_38);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x154c;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"extend_capability",iVar2);
        iVar2 = *(int *)(param_2 + 4);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1559;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_11ac",iVar2);
        iVar2 = *(int *)(param_2 + 8);
      }
      else {
        iVar2 = *(int *)(param_2 + 8);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1566;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_11ax",iVar2);
        iVar2 = *(int *)(param_2 + 0x14);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x14);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1573;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_11be",iVar2);
        iVar2 = *(int *)(param_2 + 0x18);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x18);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x1580;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_240M",iVar2);
        iVar2 = *(int *)(param_2 + 0xc);
      }
      else {
        iVar2 = *(int *)(param_2 + 0xc);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x158d;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_160M",iVar2);
        iVar2 = *(int *)(param_2 + 0x10);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x10);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x159a;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_80M_80M",iVar2);
        iVar2 = *(int *)(param_2 + 0x34);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x34);
      }
      if (iVar2 == 1) {
        iVar2 = cJSON_CreateBool(1);
        if (iVar2 == 0) {
          if (apdb_err_switch == 0) {
            return 0xffffffff;
          }
          __format = "[APDB_ERROR]%s()/line %d : Failed create json obj.\n";
          uVar5 = 0x15a7;
          goto LAB_005fd088;
        }
        cJSON_AddItemToObject(param_1,"support_WPA3",iVar2);
        iVar2 = *(int *)(param_2 + 0x110);
      }
      else {
        iVar2 = *(int *)(param_2 + 0x110);
      }
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = cJSON_CreateObject();
      if (iVar2 == 0) {
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_ERROR]%s()/line %d : Failed create multi_freq_obj.\n";
        uVar5 = 0x15b4;
      }
      else {
        if (**(int **)(param_2 + 0x110) == 0) {
          puVar4 = &DAT_00693fd4;
        }
        else {
          if (**(int **)(param_2 + 0x110) != 1) {
            cJSON_Delete(iVar2);
            if (apdb_err_switch == 0) {
              return 0xffffffff;
            }
            __format = "[APDB_ERROR]%s()/line %d : Illegal freq type.\n";
            uVar5 = 0x15c4;
            goto LAB_005fd088;
          }
          puVar4 = &DAT_006fcd40;
        }
        cJSON_AddItemToObject(param_1,puVar4,iVar2);
        iVar2 = _apdb_add_paras_to_radios(iVar2,*(undefined4 *)(param_2 + 0x110));
        if (iVar2 == 0) {
          return 0;
        }
        if (apdb_err_switch == 0) {
          return 0xffffffff;
        }
        __format = "[APDB_ERROR]%s()/line %d : _apdb_add_paras_to_radios failed.\n";
        uVar5 = 0x15ca;
      }
    }
  }
LAB_005fd088:
  printf(__format,"_apdb_add_paras_to_radios",uVar5);
  return 0xffffffff;
}

