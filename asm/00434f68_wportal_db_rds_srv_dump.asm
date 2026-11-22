; func wportal_db_rds_srv_dump @ 0x00434f68 size=0x34
  434f68:	3c040068 	lui	a0,0x68
  434f6c:	27bdffe0 	addiu	sp,sp,-32
  434f70:	afbf001c 	sw	ra,28(sp)
  434f74:	0c101dd4 	jal	0x407750
  434f78:	2484e8a0 	addiu	a0,a0,-5984
  434f7c:	3c040043 	lui	a0,0x43
  434f80:	00002821 	move	a1,zero
  434f84:	0c10bd81 	jal	0x42f604
  434f88:	2484b200 	addiu	a0,a0,-19968
  434f8c:	2404000a 	li	a0,10
  434f90:	8fbf001c 	lw	ra,28(sp)
  434f94:	08101ce4 	j	0x407390
  434f98:	27bd0020 	addiu	sp,sp,32
