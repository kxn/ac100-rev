// func capwap_parsed_packet_check @ 00587040 size=1368

undefined4 capwap_parsed_packet_check(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
    if (capwap_err_switch == 0) {
      return 0xffffffff;
    }
    iVar2 = is_target_debug_ap();
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    printf("[CW_ERROR]%32s():%4d input is wrong\n","capwap_parsed_packet_check",0x642);
    return 0xffffffff;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if (0xf < uVar1) {
    if (uVar1 != 0x16) {
      if (uVar1 < 0x17) {
        if (uVar1 == 0x12) {
          return 0;
        }
        if (0x12 < uVar1) {
          if (uVar1 == 0x14) goto LAB_005870f0;
          if (0x14 < uVar1) {
            iVar2 = cw_msg_ele_get(param_1,0xe);
            uVar4 = 0xd;
            if (iVar2 == 0) {
              return 0xffffffff;
            }
            goto LAB_00587240;
          }
LAB_0058736c:
          iVar2 = cw_msg_ele_get(param_1,0x14);
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          iVar2 = cw_msg_ele_get(param_1,0x26);
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          iVar2 = cw_msg_ele_get(param_1,0x27);
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          iVar2 = cw_msg_ele_get(param_1,0x29);
          uVar4 = 0x2c;
          if (iVar2 == 0) {
            return 0xffffffff;
          }
          goto LAB_005873b0;
        }
        if (uVar1 != 0x10) {
          if (uVar1 != 0x11) {
            return 0xffffffff;
          }
          uVar4 = 0x19;
          goto LAB_0058718c;
        }
      }
      else {
        if (uVar1 == 0x19) {
          return 0;
        }
        if (uVar1 < 0x1a) {
          if (uVar1 == 0x17) {
            return 0;
          }
          uVar4 = 0x21;
          if (uVar1 != 0x18) {
            return 0xffffffff;
          }
          goto LAB_0058718c;
        }
        if (uVar1 == 0x33dd01) {
          iVar2 = cw_msg_ele_get(param_1,0x400);
          if (iVar2 != 0) {
            return 0;
          }
          iVar2 = cw_msg_ele_get(param_1,0x403);
          if (iVar2 != 0) {
            return 0;
          }
          uVar4 = 0x414;
          goto LAB_0058718c;
        }
        if (uVar1 != 0x33dd02) {
          if (uVar1 != 0x1a) {
            return 0xffffffff;
          }
          uVar4 = 0x21;
          goto LAB_0058718c;
        }
      }
    }
    uVar4 = 0x21;
    goto LAB_0058718c;
  }
  if (0xb < uVar1) {
    return 0;
  }
  if (uVar1 == 6) {
    iVar2 = cw_msg_ele_get(param_1,0xc);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x10);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x17);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x28);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,2);
    if (iVar2 != 0) {
      return 0;
    }
    uVar4 = 3;
    goto LAB_0058718c;
  }
  if (6 < uVar1) {
    if (uVar1 == 9) {
      iVar2 = cw_msg_ele_get(param_1,0x10);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = cw_msg_ele_get(param_1,0x15);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = cw_msg_ele_get(param_1,0x16);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = cw_msg_ele_get(param_1,0x2f);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = cw_msg_ele_get(param_1,0x30);
      if (iVar2 != 0) {
        return 0;
      }
      iVar2 = cw_msg_ele_get(param_1,0x12);
      if (iVar2 != 0) {
        return 0;
      }
      cw_msg_ele_get(param_1,0x25);
      return 0;
    }
    if (9 < uVar1) {
      if (uVar1 == 10) {
        return 0;
      }
      if (uVar1 != 0xb) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,0x21);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      uVar4 = 0x20;
LAB_00587240:
      iVar2 = cw_msg_ele_get(param_1,uVar4);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      return 0;
    }
    if (uVar1 == 7) {
      return 0;
    }
    if (uVar1 != 8) {
      return 0xffffffff;
    }
    uVar4 = 0x21;
    goto LAB_0058718c;
  }
  if (uVar1 == 3) {
    iVar2 = cw_msg_ele_get(param_1,0x1c);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x26);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x27);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x2d);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x23);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x29);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x2c);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x35);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    iVar2 = cw_msg_ele_get(param_1,0x1e);
    if (iVar2 == 0) {
      uVar4 = 0x1e;
LAB_005873b0:
      iVar2 = cw_msg_ele_get(param_1,uVar4);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      cVar3 = *(char *)(param_1 + 4);
    }
    else {
      cVar3 = *(char *)(param_1 + 4);
    }
  }
  else {
    if (uVar1 < 4) {
      if (uVar1 == 1) goto LAB_0058736c;
      if (uVar1 != 2) {
        return 0xffffffff;
      }
LAB_005870f0:
      iVar2 = cw_msg_ele_get(param_1,1);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,4);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,10);
      if (iVar2 == 0) {
        uVar4 = 0xb;
        goto LAB_005873b0;
      }
    }
    else {
      if (uVar1 != 4) {
        if (uVar1 != 5) {
          return 0xffffffff;
        }
        iVar2 = cw_msg_ele_get(param_1,4);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        iVar2 = cw_msg_ele_get(param_1,0x1f);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        iVar2 = cw_msg_ele_get(param_1,0x24);
        if (iVar2 == 0) {
          return 0xffffffff;
        }
        uVar4 = 0x30;
        goto LAB_00587240;
      }
      iVar2 = cw_msg_ele_get(param_1,0x21);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,1);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,4);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,0x35);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,10);
      if ((iVar2 == 0) && (iVar2 = cw_msg_ele_get(param_1,0xb), iVar2 == 0)) {
        return 0xffffffff;
      }
      iVar2 = cw_msg_ele_get(param_1,0x1e);
      if (iVar2 != 0) {
        cVar3 = *(char *)(param_1 + 4);
        goto LAB_00587128;
      }
      iVar2 = cw_msg_ele_get(param_1,0x1e);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
    }
    cVar3 = *(char *)(param_1 + 4);
  }
LAB_00587128:
  if (cVar3 != '\x01') {
    return 0;
  }
  uVar4 = 0x418;
LAB_0058718c:
  uVar5 = 0xffffffff;
  iVar2 = cw_msg_ele_get(param_1,uVar4);
  if (iVar2 != 0) {
    uVar5 = 0;
  }
  return uVar5;
}

