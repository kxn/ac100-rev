// func arp_defend_ip4addr2str @ 004796d0 size=72

void arp_defend_ip4addr2str(uint param_1,char *param_2,size_t param_3)

{
  snprintf(param_2,param_3,"%d.%d.%d.%d",param_1 >> 0x18,(param_1 << 8) >> 0x18,
           (param_1 << 0x10) >> 0x18,param_1 & 0xff);
  return;
}

