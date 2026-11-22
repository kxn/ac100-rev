; func cw_priv_stat_prd_free @ 0x005c8054 size=0x3c
  5c8054:	27bdffe0 	addiu	sp,sp,-32
  5c8058:	afb00018 	sw	s0,24(sp)
  5c805c:	00808021 	move	s0,a0
  5c8060:	afbf001c 	sw	ra,28(sp)
  5c8064:	8c840010 	lw	a0,16(a0)
  5c8068:	10800005 	beqz	a0,0x5c8080
  5c806c:	8fbf001c 	lw	ra,28(sp)
  5c8070:	0c101f7c 	jal	0x407df0
  5c8074:	00000000 	nop
  5c8078:	ae000010 	sw	zero,16(s0)
  5c807c:	8fbf001c 	lw	ra,28(sp)
  5c8080:	00001021 	move	v0,zero
  5c8084:	8fb00018 	lw	s0,24(sp)
  5c8088:	03e00008 	jr	ra
  5c808c:	27bd0020 	addiu	sp,sp,32
