// func uac_com_get_device_basic_info @ 005183ec size=1780

undefined4 uac_com_get_device_basic_info(char *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *__s;
  char *__s_00;
  uint local_68;
  undefined2 local_64;
  char local_60 [8];
  undefined4 local_58;
  char *local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined2 local_40;
  undefined2 local_3e;
  char *local_3c;
  undefined4 local_38;
  char *local_30;
  char *local_2c;
  
  __s_00 = param_1 + 0x40;
  memset(param_1,0,0x6cc);
  local_58 = 0;
  local_50 = 1;
  local_4c = 1;
  local_54 = "device_info";
  local_48 = 0;
  local_44 = 0;
  local_40 = 1;
  local_3e = 0x44;
  local_38 = 0;
  local_3c = __s_00;
  iVar1 = uac_com_uci_parse_req("device_info","info",&local_58,1);
  if (iVar1 == 0) {
    pcVar4 = param_1 + 0x84;
    sVar2 = strlen(__s_00);
    url_encode(__s_00,sVar2,param_1 + 0x33c,0xcc);
    local_3e = 0x44;
    local_54 = "device_type";
    local_3c = pcVar4;
    iVar1 = uac_com_uci_parse_req("device_info","info",&local_58,1);
    if (iVar1 == 0) {
      __s = param_1 + 200;
      sVar2 = strlen(pcVar4);
      url_encode(pcVar4,sVar2,param_1 + 0x408,0xcc);
      local_3e = 0x24;
      local_54 = "device_model";
      local_3c = __s;
      iVar1 = uac_com_uci_parse_req("device_info","info",&local_58,1);
      if (iVar1 == 0) {
        sVar2 = strlen(__s);
        url_encode(__s,sVar2,param_1 + 0x5a0,0x6c);
        local_3e = 0x24;
        local_54 = "hw_version";
        local_3c = param_1 + 0x130;
        local_30 = local_3c;
        iVar1 = uac_com_uci_parse_req("device_info","info",&local_58,1);
        if (iVar1 == 0) {
          local_3e = 0x44;
          local_54 = "sw_version";
          local_3c = param_1 + 0x154;
          local_2c = local_3c;
          iVar1 = uac_com_uci_parse_req("device_info","info",&local_58,1);
          if (iVar1 == 0) {
            local_54 = "dev_alias";
            local_3e = 0x40;
            local_3c = param_1;
            iVar1 = uac_com_uci_parse_req("system",&DAT_00699be8,&local_58,1);
            if (iVar1 == 0) {
              pcVar4 = param_1 + 0x1f8;
              sVar2 = strlen(param_1);
              url_encode(param_1,sVar2,param_1 + 0x27c,0xc0);
              strncpy(pcVar4,param_1,0x40);
              sVar2 = strlen(pcVar4);
              url_encode(pcVar4,sVar2,param_1 + 0x60c,0xc0);
              local_60[0] = '\0';
              local_60[1] = '\0';
              local_60[2] = '\0';
              local_60[3] = '\0';
              local_60[4] = '\0';
              local_60[5] = '\0';
              local_60[6] = '\0';
              local_60[7] = '\0';
              local_54 = "bind_status";
              local_3e = 8;
              local_3c = local_60;
              iVar1 = uac_com_uci_parse_req("cloud_config","device_status",&local_58,1);
              if (iVar1 == 0) {
                iVar1 = atoi(local_60);
                if (iVar1 == 1) {
                  local_54 = "username";
                  local_3e = 0x44;
                  local_3c = param_1 + 0x238;
                  iVar1 = uac_com_uci_parse_req("cloud_config","bind",&local_58,1);
                  if ((iVar1 != 0) && (uac_comm_err_switch != 0)) {
                    printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n",
                           "uac_com_get_device_basic_info",0x8c5);
                  }
                }
                sVar2 = strlen(param_1 + 0x238);
                url_encode(param_1 + 0x238,sVar2,param_1 + 0x4d4,0xcc);
                local_68 = 0;
                local_64 = 0;
                iVar1 = uac_com_get_dev_mac(&local_68);
                if (iVar1 == 0) {
                  snprintf(param_1 + 0x11c,0x14,"%02X-%02X-%02X-%02X-%02X-%02X",local_68 >> 0x18,
                           local_68 >> 0x10 & 0xff,local_68 >> 8 & 0xff,local_68 & 0xff,
                           (uint)local_64._0_1_,(uint)(byte)local_64);
                  iVar1 = uac_com_get_dev_id(param_1 + 0xec,0x28);
                  if (iVar1 == 0) {
                    iVar1 = uac_com_get_dev_fw_id(param_1 + 0x198,0x30);
                    if (iVar1 == 0) {
                      iVar1 = uac_com_get_dev_hw_id(param_1 + 0x1c8,0x30);
                      if (iVar1 == 0) {
                        if (uac_comm_dbg_switch == 0) {
                          return 0;
                        }
                        printf("[UAC_COMM_DBG]%s()/line %d : device config: \nname[%s]\n, info[%s]\n, model[%s]\n, \t\t\t\t\thw version[%s]\n, sw version[%s]\n, alias[%s]\n, \t\t\t\t\tdevice id[%s]\n, fw id[%s]\n, hw id[%s]\n, mac[%s]\n\n"
                               ,"uac_com_get_device_basic_info",0x8f4,param_1,__s_00,__s,local_30,
                               local_2c,pcVar4,param_1 + 0xec,param_1 + 0x198,param_1 + 0x1c8,
                               param_1 + 0x11c);
                        return 0;
                      }
                      if (uac_comm_err_switch == 0) {
                        return 0xffffffff;
                      }
                      uVar3 = 0x8e9;
                    }
                    else {
                      if (uac_comm_err_switch == 0) {
                        return 0xffffffff;
                      }
                      uVar3 = 0x8e3;
                    }
                  }
                  else {
                    if (uac_comm_err_switch == 0) {
                      return 0xffffffff;
                    }
                    uVar3 = 0x8dd;
                  }
                }
                else {
                  if (uac_comm_err_switch == 0) {
                    return 0xffffffff;
                  }
                  uVar3 = 0x8d7;
                }
              }
              else {
                if (uac_comm_err_switch == 0) {
                  return 0xffffffff;
                }
                uVar3 = 0x8b9;
              }
            }
            else {
              if (uac_comm_err_switch == 0) {
                return 0xffffffff;
              }
              uVar3 = 0x8a5;
            }
          }
          else {
            if (uac_comm_err_switch == 0) {
              return 0xffffffff;
            }
            uVar3 = 0x89a;
          }
        }
        else {
          if (uac_comm_err_switch == 0) {
            return 0xffffffff;
          }
          uVar3 = 0x890;
        }
      }
      else {
        if (uac_comm_err_switch == 0) {
          return 0xffffffff;
        }
        uVar3 = 0x884;
      }
    }
    else {
      if (uac_comm_err_switch == 0) {
        return 0xffffffff;
      }
      uVar3 = 0x878;
    }
  }
  else {
    if (uac_comm_err_switch == 0) {
      return 0xffffffff;
    }
    uVar3 = 0x86b;
  }
  printf("[UAC_COMM_ERR]%s()/line %d : uci req parse failed.\n","uac_com_get_device_basic_info",
         uVar3);
  return 0xffffffff;
}

