// func _apdb_pkt_parse_radio @ 0060e514 size=1872

undefined4 _apdb_pkt_parse_radio(char *param_1,int *param_2,undefined4 *param_3)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  char *__format;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  if (*param_1 == '\0') {
    *param_2 = 0;
  }
  else {
    if (*param_1 != '\x01') {
      if (apdb_err_switch == 0) {
        return 0xffffffff;
      }
      printf("[APDB_ERROR]%s()/line %d : frequency not supported %d\n\n","_apdb_pkt_parse_radio",
             0x1d9);
      return 0xffffffff;
    }
    *param_2 = 1;
  }
  pcVar4 = param_1 + 4;
  param_2[0xc] = -1;
  bVar2 = param_1[1];
  if (apdb_debug_switch != 0) {
    printf("[APDB_DEBUG]%s()/line %d : sub_num: %d\n","_apdb_pkt_parse_radio",0x1e3,(uint)bVar2);
  }
  uVar7 = 0;
  iVar8 = 0;
  uVar6 = 0;
  do {
    if ((int)(uint)bVar2 <= iVar8) {
      if (uVar7 != 0x1e) {
        if (apdb_err_switch != 0) {
          printf("[APDB_ERROR]%s()/line %d : Not include enough radio subtype: %x\n\n",
                 "_apdb_pkt_parse_radio",0x303,uVar7);
        }
        uVar6 = 0xffffffff;
        *param_3 = 1;
      }
      return uVar6;
    }
    uVar5 = (uint)(byte)pcVar4[1];
    switch(*pcVar4 + -1) {
    case '\0':
      if (uVar5 == 2) {
        uVar7 = uVar7 | 2;
        *(undefined2 *)(param_2 + 7) = *(undefined2 *)(pcVar4 + 2);
      }
      else {
        if (apdb_err_switch == 0) goto LAB_0060e684;
        __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MAX_SSID len error: %d\n\n";
        uVar6 = 0x1ee;
LAB_0060e9a4:
        printf(__format,"_apdb_pkt_parse_radio",uVar6,uVar5);
        *param_3 = 1;
LAB_0060e688:
        uVar6 = 0xffffffff;
      }
      break;
    case '\x01':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MAX_STATION len error: %d\n\n";
          uVar6 = 0x1fc;
          goto LAB_0060e9a4;
        }
LAB_0060e684:
        *param_3 = 1;
        goto LAB_0060e688;
      }
      uVar7 = uVar7 | 4;
      *(undefined2 *)((int)param_2 + 0x1e) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\x02':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MAX_TX_POWER len error: %d\n\n";
          uVar6 = 0x20a;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      uVar7 = uVar7 | 8;
      *(undefined2 *)(param_2 + 8) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\x03':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MIN_TX_POWER len error: %d\n\n";
          uVar6 = 0x218;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      uVar7 = uVar7 | 0x10;
      *(undefined2 *)((int)param_2 + 0x22) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\x04':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_DFT_TX_POWER len error: %d\n\n";
          uVar6 = 0x226;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(undefined2 *)(param_2 + 9) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\x05':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_11AC len error: %d\n\n";
          uVar6 = 0x25a;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[1] = (uint)(pcVar4[2] != '\0');
      break;
    case '\x06':
      if (99 < uVar5) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MUTEX_CHANNEL len error: %d\n\n"
          ;
          uVar6 = 0x286;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      memcpy(param_2 + 0xe,pcVar4 + 2,uVar5);
      *(undefined1 *)((int)param_2 + uVar5 + 0x38) = 0;
      break;
    case '\a':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_DFT_BW_MODE len error: %d\n\n";
          uVar6 = 0x29a;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[0xc] = (uint)(byte)pcVar4[2];
      break;
    case '\b':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_160M len error: %d\n\n";
          uVar6 = 0x270;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[3] = (uint)(pcVar4[2] != '\0');
      break;
    case '\t':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_11AX len error: %d\n\n";
          uVar6 = 0x265;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[2] = (uint)(pcVar4[2] != '\0');
      break;
    case '\n':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          uVar6 = 0x233;
          __format = 
          "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_REAL_MAX_TX_POWER len error: %d\n\n";
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(undefined2 *)((int)param_2 + 0x26) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\v':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = 
          "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_REAL_MIN_TX_POWER len error: %d\n\n";
          uVar6 = 0x240;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(undefined2 *)(param_2 + 10) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\f':
      if (uVar5 != 2) {
        if (apdb_err_switch != 0) {
          __format = 
          "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_REAL_DFT_TX_POWER len error: %d\n\n";
          uVar6 = 0x24d;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(undefined2 *)((int)param_2 + 0x2a) = *(undefined2 *)(pcVar4 + 2);
      break;
    case '\r':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = 
          "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_80M_80M len error: %d\n\n";
          uVar6 = 0x27b;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[4] = (uint)(pcVar4[2] != '\0');
      break;
    case '\x0e':
      if (uVar5 < 7) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_MSG_TYPE_RADIOS len error: %d\n\n";
          uVar6 = 0x2a5;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      if (param_2[0x44] == 0) {
        iVar3 = FUN_00408450(0x114,0x2ac);
        param_2[0x44] = iVar3;
        if (iVar3 == 0) {
          uVar6 = 0xffffffff;
          break;
        }
      }
      memset((void *)param_2[0x44],0,0x114);
      iVar3 = _apdb_pkt_parse_radio(pcVar4 + 2,param_2[0x44],param_3);
      if ((iVar3 == 0) && (*(int *)param_2[0x44] != *param_2)) {
        uVar5 = (uint)(byte)pcVar4[1];
      }
      else {
        uVar6 = 0xffffffff;
        _apdb_radio_free((int *)param_2[0x44],1);
        bVar1 = apdb_err_switch == 0;
        param_2[0x44] = 0;
        if (bVar1) break;
        printf("[APDB_ERROR]%s()/line %d : _apdb_pkt_parse_radio failed\n\n","_apdb_pkt_parse_radio"
               ,0x2b9);
        uVar5 = (uint)(byte)pcVar4[1];
      }
      goto LAB_0060e5e4;
    case '\x0f':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MAX_TX_STREAM len error: %d\n\n"
          ;
          uVar6 = 0x2c2;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(char *)(param_2 + 0xb) = pcVar4[2];
      break;
    case '\x10':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_MAX_RX_STREAM len error: %d\n\n"
          ;
          uVar6 = 0x2cd;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      *(char *)((int)param_2 + 0x2d) = pcVar4[2];
      break;
    case '\x11':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_WPA3 len error: %d\n\n";
          uVar6 = 0x2d8;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[0xd] = (uint)(pcVar4[2] != '\0');
      break;
    case '\x12':
      iVar3 = _apdb_extend_str_transfer_to_cap(pcVar4 + 2,uVar5,param_2 + 0x40,0x10);
      if (iVar3 != 0) {
        if (apdb_err_switch != 0) {
          __format = 
          "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_EXTEND_CAPABILITY content error: %d\n\n";
          uVar6 = 0x291;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      uVar5 = (uint)(byte)pcVar4[1];
      goto LAB_0060e5e4;
    case '\x14':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_11BE len error: %d\n\n";
          uVar6 = 0x2e3;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[5] = (uint)(pcVar4[2] != '\0');
      break;
    case '\x15':
      if (uVar5 != 1) {
        if (apdb_err_switch != 0) {
          __format = "[APDB_ERROR]%s()/line %d : APDB_RADIO_SUBTYPE_SUPPORT_240M len error: %d\n\n";
          uVar6 = 0x2ee;
          goto LAB_0060e9a4;
        }
        goto LAB_0060e684;
      }
      param_2[6] = (uint)(pcVar4[2] != '\0');
    }
    uVar5 = (uint)(byte)pcVar4[1];
LAB_0060e5e4:
    iVar8 = iVar8 + 1;
    pcVar4 = pcVar4 + uVar5 + 2;
  } while( true );
}

