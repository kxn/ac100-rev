// func rrm_transfer_pwr_to_level @ 004ab198 size=164

char rrm_transfer_pwr_to_level(double param_1,uint param_2,uint param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = __floatsidf((param_2 & 0xff) - (param_4 & 0xff));
  uVar2 = __muldf3((int)((ulonglong)uVar2 >> 0x20),(int)uVar2,0x40220000,0);
  uVar3 = __floatsidf((param_3 & 0xff) - (param_4 & 0xff));
  uVar2 = __divdf3((int)((ulonglong)uVar2 >> 0x20),(int)uVar2,(int)((ulonglong)uVar3 >> 0x20),
                   (int)uVar3);
  round(param_1);
  cVar1 = __fixunsdfsi((int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  return cVar1 + '\x01';
}

