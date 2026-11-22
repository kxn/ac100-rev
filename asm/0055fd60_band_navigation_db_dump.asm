; func band_navigation_db_dump @ 0x0055fd60 size=0x3c
  55fd60:	27bdffe0 	addiu	sp,sp,-32
  55fd64:	2405ffff 	li	a1,-1
  55fd68:	afb00018 	sw	s0,24(sp)
  55fd6c:	3c10007c 	lui	s0,0x7c
  55fd70:	afbf001c 	sw	ra,28(sp)
  55fd74:	0c1020b4 	jal	0x4082d0
  55fd78:	8e045950 	lw	a0,22864(s0)
  55fd7c:	3c02007c 	lui	v0,0x7c
  55fd80:	0c15808f 	jal	0x56023c
  55fd84:	8c445954 	lw	a0,22868(v0)
  55fd88:	8e045950 	lw	a0,22864(s0)
  55fd8c:	8fbf001c 	lw	ra,28(sp)
  55fd90:	8fb00018 	lw	s0,24(sp)
  55fd94:	08101fcc 	j	0x407f30
  55fd98:	27bd0020 	addiu	sp,sp,32
