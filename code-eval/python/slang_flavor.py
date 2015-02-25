import sys
import re


COOLS = [', yeah!',
         ', this is crazy, I tell ya.',
         ', can U believe this?',
         ', eh?',
         ', aw yea.',
         ', yo.',
         '? No way!',
         '. Awesome!']
test_cases = open(sys.argv[1], 'r')
i = 0
c = 0
for test in test_cases:
    test = test.strip()
    if len(test) < 1:
        continue
    phrases = [s.strip() for s in re.split('[\.!\?]', test) if len(s) > 0]
    l = []
    for s in phrases:
        if c % 2 != 0:
            l.append(s + COOLS[i])
            i = (i + 1) % len(COOLS)
        else:
            punctuation = test[test.find(s) + len(s)]
            l.append(s + punctuation)
        c += 1
    print(' '.join(l))

test_cases.close()
