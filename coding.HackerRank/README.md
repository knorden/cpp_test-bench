# CODING PRACTICE ON HACKERRANK.COM

---
This is the practice/test space for coding challenges on HackerRank.com.

## For C++:
- I have ranked up past the Easy problems, and just stepped into the Medium problems territory.

---
### Milestone: "Vector of Variably-Sized Vectors"
This problem took me a while. The first challenge with it was that I was bigger than the previous problems. On my first run at it (as in coding without a plan), I hit the wall of errors very quickly.

I had to slow down and come back at it half a day later with a different plan. This time I reread the problem, broke it down to small chunks, solved those chunks sequentially. This helped prioritize my mental resource into solving manageable chunks instead of being scattered like on the first run.

I tried solving the loop to print output results at this end with a queue, and it was very easy.

However, I was limited to using only vectors so I had to consider this data-structure's public API. The problem was solved with a slight adjustment to the for-loop by making it increment by 2 every time.

There was a stupid bug at the end that kept breaking the code, and it turned out that I put the coordinates vector at the wrong place just a few lines above. Instead of putting it outside the loop that gets coordinate inputs, I put it INSIDE that for-loop. Stupid mistake.