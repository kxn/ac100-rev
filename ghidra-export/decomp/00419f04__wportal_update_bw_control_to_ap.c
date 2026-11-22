// func _wportal_update_bw_control_to_ap @ 00419f04 size=500

undefined4
_wportal_update_bw_control_to_ap
          (undefined4 param_1,void *param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  undefined4 *__s;
  int iVar2;
  int iVar3;
  uint local_50;
  uint local_4c;
  uint local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = (undefined4 *)0x0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar1 = cw_pkt_buf_create(0xfa);
  if (iVar1 != 0) {
    __s = (undefined4 *)FUN_00408450(10,0x1b9);
    if (__s == (undefined4 *)0x0) {
      iVar2 = 0;
    }
    else {
      memset(__s,0,10);
      *__s = 1;
      memcpy(__s + 1,param_2,6);
      if (param_3 == 0) {
        local_50 = local_50 & 0xffffff;
      }
      else if (param_3 == 1) {
        local_50 = CONCAT13(4,local_50._1_3_);
      }
      local_48 = 0;
      local_4c = 0;
      if ((param_5 != 0) && (local_4c = param_5 >> 10, local_4c == 0)) {
        local_4c = 1;
      }
      if ((param_4 != 0) && (local_48 = param_4 >> 10, local_48 == 0)) {
        local_48 = 1;
      }
      local_44 = __s;
      FUN_0051ad88(&local_38);
      local_40 = 0x12345678;
      local_3c = CONCAT22(0x45,local_3c._2_2_);
      iVar2 = cw_parsed_pkt_create(7);
      if (((iVar2 != 0) &&
          (iVar3 = cw_service_msg_add(iVar2,0x25,&local_40,1,0x45,&local_50), iVar3 != -1)) &&
         (iVar3 = capwap_packet_assemble(iVar1,iVar2), iVar3 != -1)) {
        serv_packet_send(param_1,iVar1,0);
        cw_parsed_pkt_destroy(iVar2);
        cw_pkt_buf_destroy(iVar1);
        FUN_00407df0(__s);
        return 0;
      }
    }
    cw_pkt_buf_destroy(iVar1);
    if (iVar2 != 0) {
      cw_parsed_pkt_destroy(iVar2);
    }
    if (__s == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    FUN_00407df0(__s);
  }
  return 0xffffffff;
}

