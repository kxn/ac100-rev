// func uac_ipaddr_calcu_ipv6_netmask @ 0051ac44 size=204

undefined4 uac_ipaddr_calcu_ipv6_netmask(void *param_1,int param_2,void *param_3)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((((param_1 == (void *)0x0) || (param_2 < 0)) || (0x80 < param_2)) || (param_3 == (void *)0x0))
  {
    uVar2 = 0xffffffff;
    if (uac_ip_err_switch != 0) {
      printf("[UAC_IP_ERROR]%s()/line %d : Invalid params.\n","uac_ipaddr_calcu_ipv6_netmask",0xbc);
    }
  }
  else {
    param_2 = param_2 >> 3;
    memcpy(param_3,param_1,0x10);
    if (param_2 == 0x10) {
      uVar2 = 0;
    }
    else {
      do {
        puVar1 = (undefined1 *)((int)param_3 + param_2);
        param_2 = param_2 + 1;
        *puVar1 = 0;
      } while (param_2 != 0x10);
      uVar2 = 0;
    }
  }
  return uVar2;
}

