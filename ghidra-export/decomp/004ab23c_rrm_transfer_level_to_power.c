// func rrm_transfer_level_to_power @ 004ab23c size=196

undefined1 rrm_transfer_level_to_power(double param_1,uint param_2,uint param_3,uint param_4)

{
  undefined1 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = __floatsidf((param_3 & 0xff) - (param_4 & 0xff));
  uVar3 = __floatsidf((param_2 & 0xff) - 1);
  uVar2 = __muldf3((int)((ulonglong)uVar2 >> 0x20),(int)uVar2,(int)((ulonglong)uVar3 >> 0x20),
                   (int)uVar3);
  uVar2 = __divdf3((int)((ulonglong)uVar2 >> 0x20),(int)uVar2,0x40220000,0);
  round(param_1);
  uVar3 = __floatsidf(param_4 & 0xff);
  uVar2 = __adddf3((int)((ulonglong)uVar3 >> 0x20),(int)uVar3,(int)((ulonglong)uVar2 >> 0x20),
                   (int)uVar2);
  uVar1 = __fixunsdfsi((int)((ulonglong)uVar2 >> 0x20),(int)uVar2);
  return uVar1;
}

