Release Management
==================

.. _version:

Version Scheme
--------------

FlyWithPython follows a `semantic`_ version scheme complying with `PEP 440`_.
Version indicators are of the form

  ``major.minor[.patch][{a|b|rc|.dev}N]``

with the following meaning of version components:

major
   The major version number, indicating the release family. Changes breaking
   backwards compatibility shall entail an increase of the major version number.

minor
   The minor version number, indicating the version inside a release family.
   Changes not breaking backwards compatibility (e. g. an additional feature or
   option) shall entail an increase of the minor version number.

patch
   The patch number. By default, all releases start with patch number ``0``. In
   this case, the patch number is omitted from the version information. Patches
   indicate errata fixes (either concerning security or functionality), but are
   limited to changes not modifying the product functionality or even breaking
   compatibility.

pre-release suffix (a, b, rc)
   Suffix indicating a pre-release stage of the current version, i. e. "alpha"
   (indicated by a), "beta" (indicated by b) or "release candidate" (indicated
   by rc) versions. Any pre-release suffix is mandatorily followed by a numeric
   sequence indicator (i. e. a1 = "alpha number one", rc2 = "release candidate
   number two").

.dev suffix
   The .dev suffix is mutually exclusive to pre-release suffices and indicates a
   version that is still under development. The .dev suffix is always followed
   by a numeric indicator pointing to the corresponding Git commit.


Internally, version numbers are represented as tuple with the following elements:

  ``(major, minor, patch, stage, suffix)``

Major, minor and patch are numeric (non-negative integers) with the same meaning
as indicated above.

stage
   is a flag, corresponding either to ``alpha``, ``beta``, ``rc``, or ``final``,
   marking the stage of development.

suffix
   is numeric (non-negative integer) and indicates the sequence for stages
   ``alpha``, ``beta`` and ``rc``. For the ``final`` stage, suffix has to be
   zero. If stage is set to ``alpha`` and the suffix is zero, this has a
   special meaning (development version, designated with a ``.devN`` suffix).
   For ``beta`` and ``rc`` stages, suffix must be greater than zero (minimum 1).


Release Process
---------------

Once all feature branches selected for a specific release are finalized and
merged back in ``origin/master``, the release process can start.

Stage 1: Code Slush
~~~~~~~~~~~~~~~~~~~

The first phase of a release publishing cycle starts with a code slush. Under
code slush, ``origin/master`` is not hard protected against any change, but
stabilization PRs (i. e. bug fixes, quality improvements) will get a higher
priority. The priority order expressed in PR classes:

1. *qca* (bug fixes, quality improvements)
2. *doc* (documentation updates and polishing)
3. *imp* (improvements, enhancements, optimisation)

*new* and *pro* class PRs should be avoided and postponed to after the release
has been finalized.

The code slush phase ends with production of the first alpha release.

Stage 2: Code Freeze
~~~~~~~~~~~~~~~~~~~~

The second phase begins with the release of the first alpha version. From here
on, a strict code freeze is imposed on ``origin/master``. This means no PRs will
be accepted and merged unless linked to the upcoming release. Normally, this
means only *qca* class PRs linked to issues related to the upcoming release
milestone will be considered.

Under code freeze, alpha and beta versions are tagged in master and released for
wider testing.

Stage 3: Pre-Release
~~~~~~~~~~~~~~~~~~~~

If maturity in ``origin/master`` is considered sufficient for release, a
dedicated :ref:`release branch <release-branches>` for the release is created
(``release/major.minor``). The code freeze on master persists. From now on,
release-related *qca* fixes are to be applied to the release branch. During the
pre-release phase, release candidate releases are tagged in the release branch
and published to further mature the release.

Stage 4: Release
~~~~~~~~~~~~~~~~

As soon as the maturity in the release branch is sufficient for a final release,
all pending PRs have to be either merged or rejected. The head of the release
branch has to be tagged with the final release number, and the release branch
has thereafter to be converted into a `protected branch`_.

The release itself has to be created on GitHub using the final release tag as
anchor reference.

The release branch has now to be merged back into ``origin/master``, and with a
further local PR, the version in ``origin/master`` has to be bumped to the next
release cycle (this is no final decision, it can be reverted at a later stage).
This formally lifts the code freeze on ``origin/master`` and allows to proceed
with PRs that use a properly rebased feature branch with most recent changes in
``origin/master``.

Stage 5: Maintenance
~~~~~~~~~~~~~~~~~~~~

As the release branch is now managed as protected branch, direct commits to this
branch are no longer possible. Instead, if a published release needs fixing, and
the fix is well contained so it can be contained as patch and not as minor or
even major release change, the following procedure has to be applied:

A :ref:`hotfix branch <hotfix-branches>` has to be created (outside``origin``),
based on the release branch at the last published version tag. There the
necessary amendments can be developed and matured. Once finalized, the hotfix
branch has to be merged back into the release branch via pull request, and
subsequently a new patch version has to be tagged in the release branch, and the
new patch release shall be published.

.. important::

   Support for all prior versions from a release branch cedes the moment a new
   patch version is published.

As a final step after a patch has been published, the fix needs to be introduced
to ``origin/master`` if still applicable there (e. g. an intermediate
architectural change could have removed entirely the concerned code from
``origin/master``). If still applicable, the method of injection has to be
chosen on how far ``origin/master`` has diverted from the (now patched) release
branch.

If both branches are still closely enough together, a pull request would be the
preferred technique to merge the changes into ``origin/master``. If however both
branches have diverted significantly (e. g. due to long-term support), other
techniques such as cherry-picking the patch commit or even a "manual" injection
via a dedicated feature branch might be the appropriate solution.

.. hint::

   While bringing a fix back into ``origin/master`` is mandatory, the choice of
   technique to accomplish this is subject to common sense of the
   :ref:`core team <core-team>`, as it is nearly impossible to anticipate any
   combination of factors that might arise in the future around that subject.

.. _semantic: http://semver.org/
.. _PEP 440: https://www.python.org/dev/peps/pep-0440/
.. _protected branch: https://help.github.com/articles/about-protected-branches/
