.. _issues:

Issue Management
================

Issues are managed centrally via `GitHub Issues`_. For better visualisation,
the project uses a `Kanban Board`_. Three types of labels are used to classify
issues.


.. _issue-type:

Type
----

The type label indicates what kind the issue is of. These types are available:

* **bug** marks an error within the source code or the application logic
* **regression** marks an error that was introduced by another fix or feature
* **feature** marks a request for a new feature
* **enhancement** marks a request for enhancing an existing feature
* **optimisation** marks a request for optimising a feature or the corresponding
  source code
* **quality** marks a request to improve code quality or test coverage
* **doc** marks a request for amending or updating the documentation
* **legal** marks issues related to legal affairs (e. g. licensing, patents,
  etc.)
* **infrastructure** marks issues related to the project's technical
  infrastructure
* **project** marks issues related to general project management
* **releng** marks issues related to release management (e. g. version bumps
  etc.)
* **support** marks requests for technical support


.. _issue-priority:

Priority
--------

The Stormrose Project uses these priority labels to mark issues which require
fast attention:

* **security** -- top priority label marking security issues
* **critical** -- non-security related label for top priority issues endangering
  or blocking production use

Otherwise, priorities are expressed by the sorting order within the respective
column of the `Kanban Board`_ -- an issue placed above another issue within the
column has a higher priority than the one placed below.

Priorities may be subject to review by the :ref:`core team <core-team>`. They
will adjust proposed priorities if necessary to the right level.


.. _issue-status:

Status
------

The status of an issue is not managed by a label, but instead by a column on the
`Kanban Board`_ the issue is assigned to.

The FlyWithPython project uses these columns (i. e. status messages):

* **Backlog** -- all issues that are waiting to be worked on.
* **In Progress** -- issues that are currently being worked on (i. e. a feature
  branch exists for these issues).
* **Ready** -- issues whose feature branch is considered ready for merge into
  the ``origin/master`` branch (i. e. a pull request has been created for the
  respective issue).
* **Review** -- issues which are subject to an extended review by the
  :ref:`core team <core-team>`, pending validation or feedback or whose progress
  is blocked by whatever reason. Issues with this status are subject to regular
  reviews by the core team members.
* **Rejected** -- issues which have been rejected by the
  :ref:`core team <core-team>`, usually after a longer review period. Issues
  violating FlyWithPython's project objectives or the overall Stormrose policies
  may be immediately rejected.
* **Done** -- issues that are considered complete after integration test. May be
  closed after review/confirmation.


.. _GitHub Issues: https://github.com/stormrose-va/FlyWithPython/issues
.. _Kanban Board: https://github.com/stormrose-va/FlyWithPython/projects/1
