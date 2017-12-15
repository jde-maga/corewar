.name "all_inst"
.comment "comment"

live %1
ld %1, r1
ld 1, r1
st r1, r1
st r1, 1
add r1, r2, r3
sub r1, r2, r3
or r1, r1, r1
or %1, %1, r1
or 1, 1, r1
xor r1, r1, r1
xor %1, %1, r1
xor 1, 1, r1
zjmp %1
ldi r1, %1, r1
ldi %1, %1, r1
ldi 1, %1, r1
fork %1
lld %1, r1
lld 1, r1
lldi r1, %1, r1
lldi %1, %1, r1
lldi 1, %1, r1
lfork %1
aff r1
