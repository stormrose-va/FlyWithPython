Source Code Repository
======================

.. _blessed-repository:

FlyWithPython uses `Git`_ for managing source code repositories. The project's
"blessed" Git repository (``origin``) resides at `GitHub`_. It is publicly
accessible, but only :ref:`core team members <core-team>` can push into this
blessed repository. :ref:`Developers <developers>` and other contributors are
requested to fork the repository into their personal space and offer code
changes as :ref:`pull request <pull-request>`.


Repository Structure
--------------------

.. _protected-branches:

Protected Branches
~~~~~~~~~~~~~~~~~~

The eternal branch, ``master``, is managed as `protected branch`_:

* ``master`` is the main (eternal) branch. It represents the latest state of
  development.
* direct commits to ``master`` are not permitted, instead,
  :ref:`pull requests <pull-request>` have to be used

In addition to ``master``, also :ref:`release branches <release-branches>`
become protected branches after the initial version (patch level zero) has been
released.


.. _feature-branches:

Feature Branches
~~~~~~~~~~~~~~~~

Feature branches are used to develop new features for the upcoming or a distant
future release. When starting development of a feature, the target release in
which this feature will be incorporated may well be unknown at that point. The
essence of a feature branch is that it exists as long as the feature is in
development, but will eventually be merged back into ``master``.

.. important::

   Feature branches are not intended to exist in the
   :ref:`blessed repository <blessed-repository>` itself, but instead
   they should be limited to forks and local clones of the project's `Git`_
   repository (``origin``).

* Feature branches must be branched off ``master``
* Feature branches must relate to a GitHub issue
* By convention, their name shall be prefixed with ``feature/`` and the issue
  ID they refer to
* Feature branches merge back into ``master`` via
  :ref:`pull request <pull-request>`
* Feature branches are deleted after being merged back into ``master``.
  They typically exist in developer repos only, but not in ``origin``.


.. _release-branches:

Release Branches
~~~~~~~~~~~~~~~~

Release branches support preparation of a new production release. They allow for
last-minute minor bug fixes and preparing meta-data for a release (version
number, build dates, etc.). Beyond preparation, they also serve as maintenance
branches for a release post publication of that release. Once being in
maintenance mode, release branches are managed as
:ref:`protected branches <protected-branches>`.

* Release branches must be branched off ``master``
* By convention, their name shall be prefixed with ``release/``, followed by the
  release's version number (``release/<version>``). The version number is a
  combination of ``major.minor``, without ``patch`` suffix.
* Release branches merge back into ``master`` via
  :ref:`pull request <pull-request>`. A merge of a release branch back into
  ``master`` absolutely requires a release tag to be set on the head of the
  release branch prior merging.


.. _hotfix-branches:

Hotfix Branches
~~~~~~~~~~~~~~~

Hotfix branches are very much like feature branches in that they are also meant
to introduce code changes into a :ref:`protected branch <protected-branches>`,
albeit unplanned. They arise from the necessity to act immediately upon an
undesired state of a maintained, published production version. When a critical
bug in a production version must be resolved immediately, a hotfix branch may be
branched off from the corresponding release branch that marks the production
version.

* Hotfix branches must be branched off the corresponding release tag on the
  corresponding release branch
* By convention, their name shall be prefixed with ``hotfix/``, followed by the
  release's version number and hotfix suffix, as well as a reference to the
  corresponding :ref:`issue <issues>`
  (``hotfix/<version>/<issue id>/<description>``).
* Hotfix branches merge back into the release branch eventually into ``master``
  via :ref:`pull request <pull-request>`. A merge of a hotfix branch back into
  ``master`` is only recommended if ``master`` has not evolved/diverged so much
  from the release maintenance branch that the fix hasn't lost its relevance. In
  such a case, a cherry-pick is potentially the right approach instead of a
  fully-fledged merge.


.. _git-workflow:

Git Workflow
------------

For the FlyWithPython project, we chose to follow a dedicated flow for
development. The following graph illustrates the flow:

.. image:: ../_static/advanced-git-branching-model.png

The development of a new feature, or the improvement of an existing feature
(including bug fixing) always starts with opening an :doc:`issue <issues>`.
Once the issue is created and assigned, a feature branch has to be created,
following this naming convention::

   feature/<class>/<issue id>/<description>

.. note::

   Please note that the branch name must comply with reference name rules
   (cf. `git check-ref-format`_).

The **Issue ID** is the numerical identifier generated by GitHub, padded to six
digits (left padding with ``0``).

The **class** may be one of

* *new* -- for new features
* *imp* -- for optimisation or enhancement
* *doc* -- for documentation only updates
* *pro* -- for project related changes (code reorganization, governance changes,
  ...)
* *qca* -- for quality control & assurance related changes (policy, code
  quality, ...)

Do the following in your local copy of your **own fork**:

.. code-block:: bash

   git fetch
   git checkout master
   git pull
   git checkout -b feature/new/001234/supergadget master

As soon as the feature branch is created and work has started, the related
:ref:`issue status <issue-status>` should be updated to "in progress".

.. important::

   Do not use issue closing hooks (e. g. ``Fixes #1234``) in your commit
   messages when committing to the feature branch. Closing the issue is
   reserved for the pull request.

Once the work on the feature branch is done and continuous integration testing
shows positive results, a :ref:`pull request <pull-request>` can be opened to
notify the :ref:`core team <core-team>`. The :ref:`status <issue-status>` of the
corresponding issue should be updated to "ready".

In case of acceptance, the pull request is authorised by a core team member, the
feature branch gets merged into ``master`` and can then deleted in your fork.
The :ref:`issue status <issue-status>` is updated to "Integration", which
means the issue can now be tested in the nightly builds.

Further reading on related models, including corresponding `Git`_ command line
instructions:

* `GitFlow Groundhog Day`_
* `OneFlow - a Git branching model and workflow`_
* `A stable mainline branching model for Git`_
* `A successful Git branching model considered harmful`_

.. _pull-request:

Pull Request
------------

`GitHub Pull Requests`_ are used to merge new code from a
:ref:`feature branch <feature-branches>` into a
:ref:`protected branch <protected-branches>` or from one protected branch into
another.

This section concentrates on pull requests opened by
:ref:`developers <developers>` in order to have a feature branch merged into
``origin/master``. Any other case, where pull requests are used (e. g. cleansing
of branches etc.) are processes solely played within the
:ref:`core team <core-team>`.

.. important::

   When opening a pull request from your personal fork, please consider the
   hints given in `Allowing Changes to a Pull Request`_. Otherwise it might be
   difficult to proceed with the PR.

.. hint::

   Before opening a pull request, please ensure your feature branch is updated
   (rebased) to the latest ``HEAD`` of ``origin/master``, to ensure that only
   intended code changes become part of your PR.

.. hint::

   You can use a pull request for intermediate reviews with the core team. In
   that case, keep the :ref:`status <issue-status>` of the corresponding issue
   set to "in progress", prefix the merge request title with ``[WIP]`` and do
   **not** assign the pull request to anyone.

Pull requests may be accepted straight away (mostly in very simple cases, e. g.
a simple bug fix) -- although this most likely will rather be an exception. In
such a case, the :ref:`status <issue-status>` of the corresponding issue will be
updated to "Integration" by the core team member who accepted the pull request.

If otherwise the :ref:`core team <core-team>` accepts the pull request for
review, they will update the :ref:`issue status <issue-status>` to "Review" and
assign a core team member to the pull request. In this (much more likely)
scenario, the core team member in charge will review the content of the change
request and its implications for the code in ``origin/master`` together with the
:ref:`developer <developers>` who opened the pull request.

.. note::

   Do not abuse pull requests to mature your code. As a general rule, a pull
   request should only be opened if implementation work on the feature branch is
   completed, and CI testing gives a green status.

In case of obvious immaturity or non-quality, non-compliance with governance and
:doc:`coding style <code-style>`, a pull request may be rejected by the core
team. In such a case, the core team member rejecting the pull request shall
write a justification statement (as a comment on the pull request), explaining
why this pull request has been rejected.

.. _Git: http://git-scm.com/
.. _GitHub: https://github.com/stormrose-va/FlyWithPython/
.. _Git Flow: http://nvie.com/posts/a-successful-git-branching-model/
.. _protected branch: https://help.github.com/articles/about-protected-branches/
.. _git check-ref-format: https://www.kernel.org/pub/software/scm/git/docs/git-check-ref-format.html
.. _GitHub Pull Requests: https://help.github.com/articles/about-pull-requests/
.. _Heroku Review App: https://devcenter.heroku.com/articles/github-integration-review-apps
.. _Allowing Changes to a Pull Request: https://help.github.com/articles/allowing-changes-to-a-pull-request-branch-created-from-a-fork/
.. _GitFlow Groundhog Day: https://daemotron.github.io/2017/05/02/Git-Flow-Groundhog-Day.html
.. _OneFlow - a Git branching model and workflow: http://endoflineblog.com/oneflow-a-git-branching-model-and-workflow
.. _A stable mainline branching model for Git: http://www.bitsnbites.eu/a-stable-mainline-branching-model-for-git/
.. _A successful Git branching model considered harmful: https://barro.github.io/2016/02/a-succesful-git-branching-model-considered-harmful/
