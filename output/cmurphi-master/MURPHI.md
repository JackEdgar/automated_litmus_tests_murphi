Copyright (C) 1992--1999 by the Board of Trustees of Leland Stanford
Junior University.

License to use, copy, modify, sell and/or distribute this software
and its documentation any purpose is hereby granted without royalty,
subject to the following terms and conditions:

1. The above copyright notice and this permission notice must
appear in all copies of the software and related documentation.

2. The name of Stanford University may not be used in advertising or
publicity pertaining to distribution of the software without the
specific, prior written permission of Stanford.

3. This software may not be called "Murphi" if it has been modified
in any way, without the specific prior written permission of David L.
Dill.

4. THE SOFTWARE IS PROVIDED "AS-IS" AND STANFORD MAKES NO
REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, BY WAY OF EXAMPLE,
BUT NOT LIMITATION.  STANFORD MAKES NO REPRESENTATIONS OR WARRANTIES
OF MERCHANTABILITY OR FITNESS FOR ANY PARTICULAR PURPOSE OR THAT THE
USE OF THE SOFTWARE WILL NOT INFRINGE ANY PATENTS, COPYRIGHTS
TRADEMARKS OR OTHER RIGHTS. STANFORD SHALL NOT BE LIABLE FOR ANY
LIABILITY OR DAMAGES WITH RESPECT TO ANY CLAIM BY LICENSEE OR ANY
THIRD PARTY ON ACCOUNT OF, OR ARISING FROM THE LICENSE, OR ANY
SUBLICENSE OR USE OF THE SOFTWARE OR ANY SERVICE OR SUPPORT.

LICENSEE shall indemnify, hold harmless and defend STANFORD and its
trustees, officers, employees, students and agents against any and all
claims arising out of the exercise of any rights under this Agreement,
including, without limiting the generality of the foregoing, against
any damages, losses or liabilities whatsoever with respect to death or
injury to person or damage to property arising from or out of the
possession, use, or operation of Software or Licensed Program(s) by
LICENSEE or its customers.

## Responsible use

Murphi is to be used as a DEBUGGING AID, not as a means of
guaranteeing the correctness of a design.  We do not guarantee
that all errors can be caught with Murphi.  There are many
reasons for this:

1. Specifications and verification conditions do not necessarily
capture the conditions necessary for correct operation in practice.

2. Many properties cannot be stated Murphi, including timing
requirements, performance requirements, "liveness" properties
(such as "x will eventually occur") and many others.

3. Murphi cannot verify "large" systems.  Almost always, the sizes of
various objects in the description must be modelled as being much
smaller than they are in reality, in order to make verification
feasible.  There is a high probability that design errors will only be
manifested when the objects are large.

4. The description of a design may not be consistent with what
is actually implemented.

5. Murphi may have bugs that cause errors to be overlooked.

In short, Murphi is totally inadequate for guaranteeing that there are
no errors; however, it is sometimes effective for discovering errors
that are difficult to detect by other means.

## Courtesy

Our motivation in distributing this software freely is to encourage
others to evaluate its effectiveness on a wider range of applications
than we have resources to attempt, and to provide a foundation for
further development of automatic verification techniques.

We would very much appreciate learning about other's experiences with
the system and suggestions for improvements.  Even more, we would
appreciate contributions of two kinds: additional verification
examples that can be added to the distribution, and enhancements to
the verification system.  Although we do not promise to distribute the
examples or enhancements, we may do so if feasible.

## Historical Notes

The first version of the Murphi language and verification system was
originally designed in 1990--1991 by David Dill, Andreas Drexler, Alan
Hu, and Han Yang of the Stanford University Computer Systems
Laboratory.  The first version of the program was primarily
implemented by Andreas Drexler.

The Murphi language was extensively modified and extended by David
Dill, Alan Hu, Norris Ip, Ralph Melton, Seungjoon Park, and Han Yang
in 1992.  The new version was almost entirely reimplemented by Ralph
Melton during the summer and fall of 1992.

The symmetry and multiset reduction was implemented by Norris Ip,
Ulrich Stern added the hash compaction algorithms.

Financial and other support for the design and implementation of
Murphi has come from many sources, the Defense Advanced Research
Projects Agency (under contract number N00039-91-C-0138), the National
Science Foundation (grant number MIP-8858807), the Powell Foundation,
the Stanford Center for Integrated Systems, the U.S. Office of Naval
Research, and Mitsubishi Electronic Laboratories America.  Equipment
was provided by Sun Microsystems, the Digital Equipment Corporation,
and IBM.

These notes are based on information provided to Stanford that has
not been independently verified or checked.

## Support, comments, feedback

If you need help or have comments or suggestions regarding Murphi,
please send electronic mail to <murphi@verify.stanford.edu>.  We do
not have the resources to provide commercial-quality support,
but we may be able to help you.
